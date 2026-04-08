/*Given a number n, find the count of its proper divisors (divisors excluding the number itself).
Example:
Input: n = 28
Output: 5 (divisors: 1, 2, 4, 7, 14)
For a given integer n, find the largest divisor less than n (excluding n itself).
Example:
Input: n = 100
Output: 50
*/

#include<stdio.h>

int countProperDivisors(int n){
    int count = 0;

    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(i != n) count++;
            if(i != 1 && i * i != n) count++;
        }
    }
    return count;
}

int largestDivisor(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return n / i;
        }
    }
    return 1;
}

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    printf("Count of Proper Divisors : %d\n", countProperDivisors(n));
    printf("Largest Divisor : %d", largestDivisor(n));

    return 0;
}
