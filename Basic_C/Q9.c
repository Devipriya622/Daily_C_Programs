//Reverse an integer (e.g.,12345 -> 54321) and discuss overflow for 32-bit ints.
#include<stdio.h>
#include<limits.h>
int main(){
    int num, reversed = 0;
    printf("Enter an integer:");
    scanf("%d", &num);
    
    while (num != 0) {
        int digit = num % 10;
        
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > INT_MAX % 10)) {
            printf("Overflow occurred. Cannot reverse the integer.\n");
            return 1;
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < INT_MIN % 10)) {
            printf("Underflow occurred. Cannot reverse the integer.\n");
            return 1;
        }
        
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    printf("Reversed integer: %d\n", reversed);
    return 0;
}