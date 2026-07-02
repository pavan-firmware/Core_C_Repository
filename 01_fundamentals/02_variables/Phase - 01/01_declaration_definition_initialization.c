#include <stdio.h>

int g_system_state = 1;
static int g_static_counter = 0;

int main(void)
{
    int sample_count = 3;
    int calibrated_value = sample_count * 10;

    ++g_static_counter;
    printf("sample_count=%d calibrated_value=%d global=%d static=%d\n",
           sample_count, calibrated_value, g_system_state, g_static_counter);
    return 0;
}
