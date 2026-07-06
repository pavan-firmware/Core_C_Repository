#include <stdio.h>

typedef enum
{
    STATE_IDLE,
    STATE_ARMED,
    STATE_RUNNING,
    STATE_FAULT
} SystemState;

static SystemState advance_state(SystemState current_state, int event_code)
{
    switch (current_state) {
        case STATE_IDLE:
            return (event_code == 1) ? STATE_ARMED : STATE_IDLE;
        case STATE_ARMED:
            return (event_code == 2) ? STATE_RUNNING : STATE_ARMED;
        case STATE_RUNNING:
            return (event_code == 9) ? STATE_FAULT : STATE_RUNNING;
        case STATE_FAULT:
        default:
            return STATE_FAULT;
    }
}

int main(void)
{
    SystemState state = STATE_IDLE;
    state = advance_state(state, 1);
    state = advance_state(state, 2);
    printf("state = %d\n", state);
    return 0;
}
