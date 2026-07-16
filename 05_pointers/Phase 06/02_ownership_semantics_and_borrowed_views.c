#include <stdio.h>
#include <stdlib.h>

typedef struct sensor_frame
{
    unsigned int frame_id;
    float voltage;
    float current;
} sensor_frame_t;

static sensor_frame_t *sensor_frame_create(unsigned int frame_id, float voltage, float current)
{
    sensor_frame_t *frame = malloc(sizeof *frame);
    if (frame == NULL)
    {
        return NULL;
    }

    frame->frame_id = frame_id;
    frame->voltage = voltage;
    frame->current = current;
    return frame;
}

static void sensor_frame_destroy(sensor_frame_t *frame)
{
    free(frame);
}

static void log_frame_view(const sensor_frame_t *frame)
{
    printf("frame_id=%u voltage=%.2f current=%.2f\n",
           frame->frame_id,
           frame->voltage,
           frame->current);
}

int main(void)
{
    /*
        Ownership semantics make it clear which API is responsible for freeing
        memory. A creator returns an owned pointer, a consumer can accept a
        borrowed const view, and the owner eventually destroys the object.
    */

    sensor_frame_t *owned_frame = sensor_frame_create(7U, 3.30f, 0.42f);
    if (owned_frame == NULL)
    {
        puts("allocation failed");
        return 1;
    }

    const sensor_frame_t *borrowed_view = owned_frame;

    puts("ownership semantics");
    puts("--------------------");
    log_frame_view(borrowed_view);

    puts("");
    puts("borrowed view does not own the storage and must not free it");
    puts("owner releases the storage after all readers are done");

    sensor_frame_destroy(owned_frame);
    return 0;
}
