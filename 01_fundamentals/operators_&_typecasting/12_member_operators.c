#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
===============================================================================
                    12_MEMBER_OPERATORS.C
===============================================================================

TOPIC:
    Structure Member Operators

OPERATORS:

    .    Structure Member Operator
    ->   Structure Pointer Member Operator

===============================================================================

MEMBER OPERATORS TABLE

+------------+----------------------+------------------------------+
| OPERATOR   | NAME                 | USED WITH                    |
+------------+----------------------+------------------------------+
| .          | Dot Operator         | Structure Variable           |
| ->         | Arrow Operator       | Structure Pointer            |
+------------+----------------------+------------------------------+

===============================================================================

GENERAL SYNTAX

1) DOT OPERATOR

    structure_variable.member_name

Example:

    student.age

-------------------------------------------------------------------------------

2) ARROW OPERATOR

    structure_pointer->member_name

Example:

    student_ptr->age

===============================================================================

IMPORTANT

THESE TWO ARE EQUIVALENT:

    ptr->member

AND

    (*ptr).member

-------------------------------------------------------------------------------

Example:

    student_ptr->age

Equivalent:

    (*student_ptr).age

===============================================================================

MEMORY VISUALIZATION

struct Student student;

+-------------------+
| name              |
+-------------------+
| age               |
+-------------------+
| marks             |
+-------------------+

student.age

Accesses:

    age member

-------------------------------------------------------------------------------

Student *ptr = &student;

ptr
 |
 +--------> student

ptr->age

Accesses:

    age member through pointer

===============================================================================
*/


/*
===============================================================================
STUDENT STRUCTURE
===============================================================================
*/

struct Student
{
    char name[20];

    int age;

    float marks;
};


/*
===============================================================================
NESTED STRUCTURE
===============================================================================
*/

struct Address
{
    char city[20];

    int pin_code;
};


struct Employee
{
    char name[20];

    struct Address address;
};


/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/

int main(void)
{
    /*
    ===========================================================================
    1. DOT OPERATOR (.)
    ===========================================================================
    */

    struct Student student1 =
    {
        "Pavan",
        22,
        91.5f
    };

    printf("=========================================\n");
    printf("1. DOT OPERATOR (.)\n");
    printf("=========================================\n");

    printf("Name  : %s\n",
           student1.name);

    printf("Age   : %d\n",
           student1.age);

    printf("Marks : %.2f\n\n",
           student1.marks);



    /*
    ===========================================================================
    2. MODIFY MEMBERS USING DOT OPERATOR
    ===========================================================================
    */

    student1.age = 23;

    student1.marks = 95.0f;

    printf("=========================================\n");
    printf("2. MODIFY MEMBERS USING DOT\n");
    printf("=========================================\n");

    printf("Age   : %d\n",
           student1.age);

    printf("Marks : %.2f\n\n",
           student1.marks);



    /*
    ===========================================================================
    3. ARROW OPERATOR (->)
    ===========================================================================
    */

    struct Student *student_ptr = &student1;

    printf("=========================================\n");
    printf("3. ARROW OPERATOR (->)\n");
    printf("=========================================\n");

    printf("Name  : %s\n",
           student_ptr->name);

    printf("Age   : %d\n",
           student_ptr->age);

    printf("Marks : %.2f\n\n",
           student_ptr->marks);



    /*
    ===========================================================================
    4. MODIFY MEMBERS USING ARROW OPERATOR
    ===========================================================================
    */

    student_ptr->age = 24;

    student_ptr->marks = 98.0f;

    printf("=========================================\n");
    printf("4. MODIFY MEMBERS USING ARROW\n");
    printf("=========================================\n");

    printf("Age   : %d\n",
           student_ptr->age);

    printf("Marks : %.2f\n\n",
           student_ptr->marks);



    /*
    ===========================================================================
    5. ARROW OPERATOR INTERNALLY
    ===========================================================================
    */

    printf("=========================================\n");
    printf("5. ARROW OPERATOR INTERNALLY\n");
    printf("=========================================\n");

    printf("student_ptr->age      = %d\n",
           student_ptr->age);

    printf("(*student_ptr).age    = %d\n\n",
           (*student_ptr).age);



    /*
    ===========================================================================
    6. NESTED STRUCTURE ACCESS
    ===========================================================================
    */

    struct Employee employee1 =
    {
        "Ravi",
        {
            "Hyderabad",
            500001
        }
    };

    printf("=========================================\n");
    printf("6. NESTED STRUCTURES\n");
    printf("=========================================\n");

    printf("Employee Name : %s\n",
           employee1.name);

    printf("City          : %s\n",
           employee1.address.city);

    printf("PIN Code      : %d\n\n",
           employee1.address.pin_code);



    /*
    ===========================================================================
    7. NESTED STRUCTURE POINTER ACCESS
    ===========================================================================
    */

    struct Employee *employee_ptr = &employee1;

    printf("=========================================\n");
    printf("7. NESTED POINTER ACCESS\n");
    printf("=========================================\n");

    printf("Employee Name : %s\n",
           employee_ptr->name);

    printf("City          : %s\n",
           employee_ptr->address.city);

    printf("PIN Code      : %d\n\n",
           employee_ptr->address.pin_code);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    employee1

    +-------------------+
    | name              |
    +-------------------+
    | address           |
    |   city            |
    |   pin_code        |
    +-------------------+

    Access:

        employee1.address.city

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    SENSOR DATA STRUCTURE
    ===========================================================================
    */

    struct SensorData
    {
        uint16_t temperature;

        uint16_t humidity;

        bool sensor_ready;
    };

    struct SensorData sensor =
    {
        28,
        65,
        true
    };

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("Temperature  : %u\n",
           sensor.temperature);

    printf("Humidity     : %u\n",
           sensor.humidity);

    printf("Ready        : %d\n\n",
           sensor.sensor_ready);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    POINTER TO SENSOR DATA
    ===========================================================================
    */

    struct SensorData *sensor_ptr = &sensor;

    sensor_ptr->temperature = 30;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("Temperature  : %u\n\n",
           sensor_ptr->temperature);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    HARDWARE REGISTER STRUCTURE

    Real Embedded Example:

    typedef struct
    {
        volatile uint32_t MODER;
        volatile uint32_t OTYPER;
        volatile uint32_t OSPEEDR;
        volatile uint32_t PUPDR;
        volatile uint32_t IDR;
        volatile uint32_t ODR;
    } GPIO_TypeDef;

    ---------------------------------------------------------------------------

    GPIO_TypeDef *GPIOA =
        (GPIO_TypeDef *)0x48000000;

    ---------------------------------------------------------------------------

    Turn ON LED:

        GPIOA->ODR |= (1U << 5);

    ---------------------------------------------------------------------------

    This is why:

        ->

    is extremely important in Embedded Systems.

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        struct Student *ptr;

        ptr.age

    ERROR:

        Use:

            ptr->age

    ----------------------------------------

    WRONG:

        (*ptr.age)

    ERROR:

        Dot has higher precedence.

    RIGHT:

        (*ptr).age

    ----------------------------------------

    WRONG:

        NULL pointer access

            ptr->age

    Always check:

        if (ptr != NULL)

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Difference between:

            .

        and

            ->

        Answer:

            .  -> Structure Variable

            -> -> Structure Pointer

    ----------------------------------------

    Q2:

        Is:

            ptr->age

        same as:

            (*ptr).age

        Answer:

            YES

    ----------------------------------------

    Q3:

        Which operator is used heavily
        in Embedded Systems?

        Answer:

            ->

    ----------------------------------------

    Q4:

        Why?

        Answer:

            Hardware registers are usually
            accessed through pointers to
            structures.

    ===========================================================================
    */

    return 0;
}
