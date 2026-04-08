/*
In an array where every element appears twice except one, find the unique element using bitwise XOR.
Example:
Input: [2, 3, 2, 4, 4] → Output: 3.
Write a function that determines if an integer n is a power of two using bitwise operations.
Hint: A number is a power of two if n > 0 and (n & (n - 1)) == 0.
Example:
Input: n = 16 → Output: True.
*/

#include<stdio.h>
#include<stdbool.h>

void unique() {
    int n;
    printf("Enter N :");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements :");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int xor = 0;

    for(int i = 0; i < n; i++) {
        xor = xor ^ arr[i];
    }

    printf("Unique element: %d\n", xor);
}

bool power() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    if(n > 0 && (n & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main() {
    unique();

    if(power())
        printf("Power of 2\n");
    else
        printf("Not a Power of 2\n");

    return 0;
}
