#include <stdio.h>
#include <stdlib.h>
#include "c_cpp_helper.h"

void c_cpp_helper(void)
{
    int choice;

    do {
        printf("C vs C++ QUICK HELPER & COMPARISON\n\n");
        printf("1. Learn about if-else in C vs C++\n");
        printf("2. Compare I/O (printf/scanf vs cin/cout)\n");
        printf("3. C99 stdbool.h vs C++ Native Bool\n");
        printf("4. Memory Management (malloc/free vs new/delete)\n");
        printf("5. Back / Exit\n\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        system("clear");
        switch (choice) {
            case 1:
                printf("IF-ELSE IN C VS C++\n\n");
                printf("In C:\n");
                printf("  Uses integer values to evaluate conditions.\n");
                printf("  0 means FALSE, any NON-ZERO value means TRUE.\n");
                printf("  Example: if (1) { /* Always runs */ }\n\n");
                printf("In C++:\n");
                printf("  Has native 'bool' type with 'true' and 'false'.\n");
                printf("  Conditions like if (expr) still implicitly convert numbers to bool.\n");
                break;

            case 2:
                printf("PRINTF/SCANF (C) VS CIN/COUT (C++)\n\n");
                printf("C (printf / scanf):\n");
                printf("  Pure functions inside <stdio.h>.\n");
                printf("  Requires explicit format specifiers: %%d, %%s, %%f, %%p.\n");
                printf("  Minimal memory footprint, perfect for lightweight CLI tools.\n\n");
                printf("C++ (cin / cout):\n");
                printf("  Stream objects inside <iostream>.\n");
                printf("  Automatically detects data types via operator overloading (<<, >>).\n");
                printf("  Convenient, but increases binary size.\n");
                break;

            case 3:
                printf("BOOLEAN TYPES\n\n");
                printf("In C:\n");
                printf("  C89/C90 has no native bool type.\n");
                printf("  Since C99, you must include <stdbool.h> to use 'bool', 'true', 'false'.\n\n");
                printf("In C++:\n");
                printf("  'bool', 'true', and 'false' are built-in keywords.\n");
                break;

            case 4:
                printf("MEMORY MANAGEMENT\n\n");
                printf("In C:\n");
                printf("  Uses malloc(), calloc(), realloc() for Heap allocation.\n");
                printf("  Manual memory cleanup required using free() to prevent leaks.\n\n");
                printf("In C++:\n");
                printf("  Uses 'new' and 'delete' (or 'delete[]').\n");
                printf("  Supports RAII and Smart Pointers (unique_ptr, shared_ptr) for safety.\n");
                break;

            case 5:
            case 0:
                printf("Exiting C/C++ Helper.\n");
                choice = 0;
                exit(1);

            default:
                printf("Invalid choice!\n");
                break;
        }

        if (choice != 0) {
            printf("\n[Press Enter to continue...]");
            while (getchar() != '\n');
            getchar();
        }

    } while (choice != 0);
}
