//Implement a menu-driven calculator using an array of function pointers.

#include <stdio.h>
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int divi(int a, int b) {
    if (b == 0) {
        printf("Division by zero error\n");
        return 0;
    }
    return a / b;
}

int main() {
    int (*operations[4])(int, int) = {add, sub, mul, divi};
    int choice, x, y;

    while (1) {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice < 1 || choice > 4) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &x, &y);
        int result = operations[choice - 1](x, y);

        printf("Result = %d\n", result);
    }

    return 0;
}
