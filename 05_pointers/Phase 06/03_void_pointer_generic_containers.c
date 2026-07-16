#include <stdio.h>
#include <stdlib.h>

typedef void (*item_destroy_fn)(void *);
typedef void (*item_print_fn)(const void *);

typedef struct generic_slot
{
    void *value;
    item_destroy_fn destroy;
} generic_slot_t;

typedef struct generic_box
{
    generic_slot_t slots[4];
    size_t count;
} generic_box_t;

static void generic_box_init(generic_box_t *box)
{
    box->count = 0U;
}

static int generic_box_push(generic_box_t *box, void *value, item_destroy_fn destroy)
{
    if (box->count >= sizeof box->slots / sizeof box->slots[0])
    {
        return 0;
    }

    box->slots[box->count].value = value;
    box->slots[box->count].destroy = destroy;
    box->count += 1U;
    return 1;
}

static void generic_box_destroy(generic_box_t *box)
{
    for (size_t index = 0; index < box->count; ++index)
    {
        if (box->slots[index].destroy != NULL)
        {
            box->slots[index].destroy(box->slots[index].value);
        }
    }
}

static void print_integer_item(const void *item)
{
    printf("integer item = %d\n", *(const int *)item);
}

static void print_label_item(const void *item)
{
    printf("label item   = %s\n", (const char *)item);
}

static void destroy_heap_int(void *item)
{
    free(item);
}

int main(void)
{
    /*
        void* is the common foundation for generic containers in C. The
        container stores opaque payloads, while callbacks recover the typed
        meaning at the edges of the API.
    */

    generic_box_t box;
    generic_box_init(&box);

    int *heap_value = malloc(sizeof *heap_value);
    if (heap_value == NULL)
    {
        return 1;
    }

    *heap_value = 128;

    const char *board_label = "power_rail_monitor";

    generic_box_push(&box, heap_value, destroy_heap_int);
    generic_box_push(&box, (void *)board_label, NULL);

    puts("generic void* container");
    puts("-----------------------");

    print_integer_item(box.slots[0].value);
    print_label_item(box.slots[1].value);

    generic_box_destroy(&box);
    puts("");
    puts("The container owns heap-backed items through callbacks, while borrowed");
    puts("items are stored as non-owning views.");

    return 0;
}
