#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define container_of(member_ptr, type, member) \
    ((type *)((char *)(member_ptr) - offsetof(type, member)))

typedef struct intrusive_node
{
    struct intrusive_node *next;
    struct intrusive_node *previous;
} intrusive_node_t;

typedef struct telemetry_record
{
    unsigned int record_id;
    char channel_name[24];
    intrusive_node_t link;
} telemetry_record_t;

typedef void (*generic_destroy_fn)(void *);
typedef void (*generic_visit_fn)(const void *);

typedef struct generic_slot
{
    void *object;
    generic_destroy_fn destroy;
} generic_slot_t;

typedef struct generic_table
{
    generic_slot_t slots[4];
    size_t count;
} generic_table_t;

static void intrusive_list_init(intrusive_node_t *sentinel)
{
    sentinel->next = sentinel;
    sentinel->previous = sentinel;
}

static void intrusive_list_push_back(intrusive_node_t *sentinel, intrusive_node_t *node)
{
    node->previous = sentinel->previous;
    node->next = sentinel;
    sentinel->previous->next = node;
    sentinel->previous = node;
}

static void telemetry_record_init(telemetry_record_t *record, unsigned int record_id, const char *channel_name)
{
    record->record_id = record_id;
    snprintf(record->channel_name, sizeof record->channel_name, "%s", channel_name);
    record->link.next = NULL;
    record->link.previous = NULL;
}

static void print_intrusive_records(const intrusive_node_t *sentinel)
{
    const intrusive_node_t *cursor = sentinel->next;

    while (cursor != sentinel)
    {
        const telemetry_record_t *record = container_of(cursor, telemetry_record_t, link);
        printf("record_id=%u channel=%s\n", record->record_id, record->channel_name);
        cursor = cursor->next;
    }
}

static void generic_table_init(generic_table_t *table)
{
    table->count = 0U;
}

static int generic_table_add_owned(generic_table_t *table, void *object, generic_destroy_fn destroy)
{
    if (table->count >= sizeof table->slots / sizeof table->slots[0])
    {
        return 0;
    }

    table->slots[table->count].object = object;
    table->slots[table->count].destroy = destroy;
    ++table->count;
    return 1;
}

static int generic_table_add_borrowed(generic_table_t *table, const void *object)
{
    return generic_table_add_owned(table, (void *)object, NULL);
}

static void generic_table_visit(const generic_table_t *table, generic_visit_fn visit)
{
    for (size_t index = 0; index < table->count; ++index)
    {
        visit(table->slots[index].object);
    }
}

static void generic_table_destroy(generic_table_t *table)
{
    for (size_t index = 0; index < table->count; ++index)
    {
        if (table->slots[index].destroy != NULL)
        {
            table->slots[index].destroy(table->slots[index].object);
        }
    }

    table->count = 0U;
}

static void destroy_owned_record(void *object)
{
    free(object);
}

static void print_record_view(const void *object)
{
    const telemetry_record_t *record = object;
    printf("generic view: record_id=%u channel=%s\n", record->record_id, record->channel_name);
}

int main(void)
{
    /*
        This final pointer lesson ties together the expert patterns:
        - container_of recovers the outer object from an embedded node
        - intrusive linked lists store linkage inside the payload
        - ownership rules distinguish owned heap objects from borrowed views
        - void* generic containers move type knowledge to API boundaries
    */

    intrusive_node_t ready_records;
    generic_table_t table;
    telemetry_record_t stack_record;
    telemetry_record_t *owned_record = malloc(sizeof *owned_record);

    if (owned_record == NULL)
    {
        puts("allocation failed");
        return 1;
    }

    intrusive_list_init(&ready_records);
    generic_table_init(&table);

    telemetry_record_init(&stack_record, 100U, "stack_adc_sample");
    telemetry_record_init(owned_record, 200U, "heap_can_frame");

    intrusive_list_push_back(&ready_records, &stack_record.link);
    intrusive_list_push_back(&ready_records, &owned_record->link);

    (void)generic_table_add_borrowed(&table, &stack_record);
    if (!generic_table_add_owned(&table, owned_record, destroy_owned_record))
    {
        destroy_owned_record(owned_record);
        return 1;
    }

    puts("expert pointer containers, ownership, and genericity");
    puts("----------------------------------------------------");
    puts("intrusive list using container_of:");
    print_intrusive_records(&ready_records);

    puts("");
    puts("generic void* table:");
    generic_table_visit(&table, print_record_view);

    puts("");
    puts("ownership summary:");
    puts("- stack_record is borrowed and must not be freed by the table");
    puts("- owned_record is heap-backed and released through a destroy callback");
    puts("- intrusive nodes avoid separate list-node allocation");

    generic_table_destroy(&table);
    return 0;
}
