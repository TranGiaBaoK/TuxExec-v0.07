#include <stdio.h>
#include <string.h>
#include "calculator.h"

void run_calculator() {
    char input[256];
    int num1, num2;
    char op;
    int result = 0;

    printf("\nTuxExec >> Enter math expression (e.g., 5 + 3): ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;

        if (sscanf(input, "%d %c %d", &num1, &op, &num2) == 3) {
            switch (op) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': 
                    if (num2 != 0) result = num1 / num2;
                    else {
                        printf("Error: Division by zero\n");
                        return;
                    }
                    break;
                default:
                    printf("Error: Unsupported operator\n");
                    return;
            }
            printf("Result: %d\n", result);
        } else {
            printf("Error: Invalid format. Use 'num op num'\n");
        }
    }
}
