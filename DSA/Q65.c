/* Write a program that:

Takes an integer n.
Returns its prime factorization in ascending order.
Example:
Input: n = 84 → Output: 2^2 × 3 × 7
*/
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    int first = 1;

    for(int i = 2; i * i <= n; i++){
        int count = 0;

        while(n % i == 0){
            count++;
            n /= i;
        }

        if(count > 0){
            if(!first) printf(" x ");
            printf("%d", i);
            if(count > 1) printf("^%d", count);
            first = 0;
        }
    }

    if(n > 1){
        if(!first) printf(" x ");
        printf("%d", n);
    }

    return 0;
}
