#include <stdio.h>

int main(void) {
    // Define a structure that contains a union

    struct SensorData {
        int sensorId;
        union {
            float temperature;
            int pressure;
            char status[10];
        } data;
    };

    // here the sensorData structure can hold either a temperature (float), pressure (int), or status (char array) for a given sensorId, here sensorId is mandatory so we not initialize in the union.

    // Initialize the structure with temperature data
    struct SensorData sensor1;
    sensor1.sensorId = 1;
    sensor1.data.temperature = 25.5;

    // Initialize the structure with pressure data
    struct SensorData sensor2;
    sensor2.sensorId = 2;
    sensor2.data.pressure = 1013;

    // Initialize the structure with status data
    struct SensorData sensor3;
    sensor3.sensorId = 3;
    snprintf(sensor3.data.status, sizeof(sensor3.data.status), "OK");

    // Access the structure members
    printf("Sensor 1:\n");
    printf("Sensor ID: %d\n", sensor1.sensorId);
    printf("Temperature: %.2f\n", sensor1.data.temperature);

    printf("Sensor 2:\n");
    printf("Sensor ID: %d\n", sensor2.sensorId);
    printf("Pressure: %d\n", sensor2.data.pressure);

    printf("Sensor 3:\n");
    printf("Sensor ID: %d\n", sensor3.sensorId);
    printf("Status: %s\n", sensor3.data.status);

    return 0;
}