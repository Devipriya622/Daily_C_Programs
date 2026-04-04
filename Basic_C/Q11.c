//Write a program in C to check Armstrong and Perfect numbers using the function.
#include<stdio.h>
#include<math.h>
int is_armstrong(int num) {
    int original_num = num, sum = 0, n = 0;
    
    while (original_num != 0) {
        original_num /= 10;
        n++;
    }
    
    original_num = num;
    while (original_num != 0) {
        int digit = original_num % 10;
        sum += pow(digit, n);
        original_num /= 10;
    }
    
    return sum == num;
}