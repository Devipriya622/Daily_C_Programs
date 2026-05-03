//Create and use a function pointer to select different arithmetic operations at runtime.

#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divi(int a, int b) {
    if (b == 0) {
        printf("Division by zero error\n");
        return 0;
    }
    return a / b;
}
int main() {
    int x, y, choice;
    int (*operation)(int, int);
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("\nChoose operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1: operation = add; break;
        case 2: operation = sub; break;
        case 3: operation = mul; break;
        case 4: operation = divi; break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    int result = operation(x, y);
    printf("Result = %d\n", result);
    return 0;
}
