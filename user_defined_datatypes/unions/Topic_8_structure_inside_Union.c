#include <stdio.h>

int main(void) {
    // Define a union with a structure inside
    union UARTData {
        struct {
            unsigned char startByte;
            unsigned char dataByte;
            unsigned char stopByte;
        } frame;
        unsigned int rawData;
    };

    // here the UARTData union can hold either a structured frame (with startByte, dataByte, and stopByte) or a rawData (unsigned int).
    //here either one is enough here diffrence b/w struct group and rawData is that struct group is used to group related data together, while rawData is used to represent the entire UART frame as a single unsigned integer value.
    // so there are two ways to access the data in the union, either through the structured frame or through the rawData value. The union allows us to access the same memory location as either a structured frame or as a rawData value. 

    // Initialize the union with structured frame data
    union UARTData uart1;
    uart1.frame.startByte = 0x02;
    uart1.frame.dataByte = 0xA5;
    uart1.frame.stopByte = 0x03;
    // uart1.rawData = 0;

    union UARTData uart2;
    uart2.rawData = 0x02A503;
    // uart2.frame.startByte = 0x02;
    // uart2.frame.dataByte = 0xA5;
    // uart2.frame.stopByte = 0x03;

    // Access the union members
    printf("UART 1:\n");
    printf("Start Byte: 0x%02X\n", uart1.frame.startByte); // here %02X is used to print the hexadecimal value of the startByte, dataByte, and stopByte in 2 digits with leading zeros if necessary.
    // 0 meaning the value is printed in hexadecimal format, 2 means the width of the output is 2 characters, and X means the value is printed in uppercase hexadecimal format (x for lowercase).
    printf("Data Byte: 0x%02X\n", uart1.frame.dataByte);
    printf("Stop Byte: 0x%02X\n", uart1.frame.stopByte);
    printf("Raw Data: 0x%08X\n", uart1.rawData);

    printf("UART 2:\n");
    printf("Start Byte: 0x%02X\n", uart2.frame.startByte);
    printf("Data Byte: 0x%02X\n", uart2.frame.dataByte);
    printf("Stop Byte: 0x%02X\n", uart2.frame.stopByte);
    printf("Raw Data: 0x%08X\n", uart2.rawData);

    return 0;
}