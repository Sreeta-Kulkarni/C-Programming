# Structures, Unions & Pointers in C

## 💻 Programs

1. [`01_book_structure.c`](./01_book_structure.c) — Book structure — input & display 3 books
2. [`02_employee_nested_structure.c`](./02_employee_nested_structure.c) — Employee structure with a nested Address structure
3. [`03_union_temp_humidity.c`](./03_union_temp_humidity.c) — Union storing Temperature or Humidity — demonstrates shared memory
4. [`04_swap_using_pointers.c`](./04_swap_using_pointers.c) — Swap two numbers using pointers
5. [`05_array_of_pointers_cities.c`](./05_array_of_pointers_cities.c) — Array of pointers to store & print 5 city names
6. [`06_matrix_pointer_to_array.c`](./06_matrix_pointer_to_array.c) — Read and print a 3×3 matrix using pointer to an array

## 🛠️ How to compile & run

```bash
gcc 01_book_structure.c -o output
./output
```
Run the same way for any of the other 5 files in this folder — just swap the filename.

## 📖 Theory

Lab 1C: Structures, Unions & Pointers in C
What is a Structure?
A structure is a user-defined data type that allows grouping variables of different data types
under one name.
“Used when we want to represent a real-world entity”
Example:
A student has:
- Roll number (int)

- Name (string)

- Marks (float)

Syntax:
struct Student {
int roll;
char name[50];
float marks;
};

Nested Structure
A structure inside another structure.
Example:
A student also has a date of birth.

Syntax:
struct Date {
int day, month, year;
};
struct Student {
int roll;
char name[50];
struct Date dob;
};

Example Program 1: Basic Structure
```c
#include <stdio.h>
#include <string.h>
struct Student {
int roll;
char name[50];
float marks;
};
int main() {
struct Student s1;
s1.roll = 101;
strcpy(s1.name, "Arjun");
s1.marks = 88.5;
printf("Roll: %d\nName: %s\nMarks: %.2f\n", s1.roll, s1.name, s1.marks);
return 0;
}
```
Example Program 2: Nested Structure
```c
#include <stdio.h>
struct Date {
int day, month, year;
};
struct Student {
int roll;
char name[50];
struct Date dob;
};
int main() {
struct Student s = {101, "Meera", {15, 8, 2005}};
printf("Name: %s\nDOB: %d-%d-%d\n",
s.name, s.dob.day, s.dob.month, s.dob.year);
return 0;
}
```
What is a Union?
A union is similar to a structure, but all members share the same memory location.
“Only one member can store a value at a time.”
Syntax:
union Data {
int i;
float f;
char str[20];
};

Example Program 3: Union
```c
#include <stdio.h>
#include <string.h>
union Data {
int i;
float f;
char str[20];
};
int main() {
union Data d;
d.i = 10;
printf("Integer: %d\n", d.i);
d.f = 5.5;
printf("Float: %.2f\n", d.f);
strcpy(d.str, "Hello");
printf("String: %s\n", d.str);
return 0;
}
```
Note: Each new value overwrites the previous one.

What is a Pointer?
A pointer stores the address of another variable.

Example Program 4: Basic Pointer
```c
#include <stdio.h>
int main() {
int x = 10;

// Declare an integer variable 'x' and initialize it with value 10

int *p = &x;

// Declare a pointer 'p' that stores the address of variable 'x', '&x' means "address of x”

printf("Value of x: %d\n", x);

// Prints the actual value stored in variable x

printf("Address of x: %p\n", &x); // Prints the memory address where x is stored

printf("Pointer p stores: %p\n", p); // Prints address stored inside pointer p, same as the address of x

printf("Value using pointer: %d\n", *p);

// '*p' is called DEREFERENCING the pointer

/*
Dereferencing means accessing the value stored at the memory address held by the pointer.
Since pointer 'p' stores the address of variable 'x', using *p gives the value of x (which is 10).
*/
return 0; // Indicates successful program termination
}
```
What is an Array of Pointers?
An array where each element is a pointer.
“Commonly used for list of strings”
Syntax:
data_type *array_name[size];
Example Program 4: Array of Pointers
```c
#include <stdio.h>
int main() {
char *fruits[] = {"Apple", "Banana", "Cherry", "Date"}; // Declare an array of pointers to strings
int size = sizeof(fruits) / sizeof(fruits[0]);
for (int i = 0; i < size; i++) {
printf("Fruit[%d]: %s\n", i, fruits[i]);

// Print the strings using the array of pointers
// %s format specifier for string

}
return 0;
}
```
What Happens in Memory?

Memory Efficiency: Arrays of pointers save memory, especially when handling large or variablesized data like strings, as only the pointers (addresses) are stored contiguously, not the actual data.
Access: Elements are accessed using array indexing (arr_ptr[i]) and the dereference operator (*)
to get the value at the stored address (*arr_ptr[i]).

What is Pointer to an Array?
A pointer to an array is a pointer that stores the address of an entire array, not just a single
element. It points to the whole block of memory containing the array.
“Commonly used when passing multi-dimensional arrays to functions”
Syntax:
data_type (*pointer_name)[size];
Note: Parentheses are important, without them, it becomes an array of pointers instead!
Example Program 5: Pointer to an Array
```c
#include <stdio.h>
int main() {
int numbers[5] = {10, 20, 30, 40, 50};

// Declare and initialize an array

int (*ptr)[5] = &numbers;

// 'ptr' is a pointer to the entire array of 5 integers

// &numbers gives the address of the whole array
for (int i = 0; i < 5; i++) {
printf("numbers[%d]: %d\n", i, (*ptr)[i]); // (*ptr)[i] accesses the i-th element of the array
}
return 0;
}
```
