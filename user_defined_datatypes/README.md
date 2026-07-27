# User-Defined Data Types in C

This folder contains examples and practice programs for **User-Defined Data Types (UDTs)** in the C programming language.

User-defined data types allow programmers to create custom data representations by combining or organizing existing data types. They improve code readability, maintainability, and modularity, and are widely used in embedded systems, firmware development, device drivers, and application software.

The examples in this folder progress from the fundamentals to advanced concepts commonly used in real-world embedded firmware.

---

## Learning Objectives

After completing this folder, you will understand how to:

- Create meaningful data types using `enum`, `struct`, and `union`.
- Organize related data into structures.
- Represent mutually exclusive data using unions.
- Improve code readability using enumerations.
- Build complex data models using nested structures and unions.
- Pass and return user-defined data types between functions.
- Design efficient memory layouts for embedded applications.

---

# Folder Structure

## Enum

Learn how to create named integral constants using the `enum` keyword.

Topics:

- Introduction to Enumerations
- Explicit Enum Value Assignment
- Negative Enum Values
- Duplicate Enum Values
- `sizeof(enum)`

---

## Structures

Learn how to group multiple related variables into a single user-defined type.

Topics:

- Structure Basics
- Structures Containing Arrays
- Arrays of Structures
- Nested Structures
- Arrays Inside Nested Structures

---

## Unions

Learn how multiple members can share the same memory location to achieve memory-efficient data storage.

Topics:

- Introduction to Unions
- Tagged Unions
- Anonymous Unions
- Nested Unions
- Union Inside Structure
- Structure Inside Union
- Arrays of Unions
- Passing Union to Functions
- Returning Union from Functions
- Designated Initializers

---

# Target Audience

This folder is intended for:

- C Programming Beginners
- Embedded Systems Students
- Firmware Developers
- Device Driver Developers
- Interview Preparation
- Anyone learning advanced C programming concepts

---

# Prerequisites

Before starting this folder, you should understand:

- Variables
- Data Types
- Operators
- Storage Classes
- Functions
- Arrays
- Pointers

---

# Outcome

After completing all topics, you will be able to design custom data types, organize complex data efficiently, and write cleaner, scalable C programs suitable for embedded firmware and system-level programming.
