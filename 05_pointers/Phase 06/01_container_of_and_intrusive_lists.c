#include <stddef.h>
#include <stdio.h>

#define container_of(member_ptr, type, member) \
    ((type *)((char *)(member_ptr) - offsetof(type, member)))

typedef struct list_node
{
    struct list_node *next;
    struct list_node *previous;
} list_node_t;

typedef struct process_record
{
    unsigned int process_id;
    const char *name;
    list_node_t link;
} process_record_t;

static void list_init(list_node_t *sentinel)
{
    sentinel->next = sentinel;
    sentinel->previous = sentinel;
}

static void list_insert_tail(list_node_t *sentinel, list_node_t *node)
{
    node->previous = sentinel->previous;
    node->next = sentinel;
    sentinel->previous->next = node;
    sentinel->previous = node;
}

static void print_process_list(const list_node_t *sentinel)
{
    const list_node_t *cursor = sentinel->next;

    while (cursor != sentinel)
    {
        const process_record_t *record = container_of(cursor, process_record_t, link);
        printf("process_id=%u name=%s\n", record->process_id, record->name);
        cursor = cursor->next;
    }
}

int main(void)
{
    /*
        container_of converts a pointer to a struct member back into the
        pointer to the outer object. That pattern powers intrusive containers:
        the link node lives inside the payload object, so there is no extra
        allocation for the list node itself.
    */

    list_node_t ready_queue;
    list_init(&ready_queue);

    process_record_t control_loop =
    {
        .process_id = 10U,
        .name = "control_loop"
    };

    process_record_t telemetry_task =
    {
        .process_id = 20U,
        .name = "telemetry_task"
    };

    process_record_t watchdog_task =
    {
        .process_id = 30U,
        .name = "watchdog_task"
    };

    list_insert_tail(&ready_queue, &control_loop.link);
    list_insert_tail(&ready_queue, &telemetry_task.link);
    list_insert_tail(&ready_queue, &watchdog_task.link);

    puts("intrusive list traversal");
    puts("------------------------");
    print_process_list(&ready_queue);

    puts("");
    puts("The list node is embedded in each record, which keeps the storage");
    puts("layout compact and makes object ownership very explicit.");

    return 0;
}
