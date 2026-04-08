/*A password consists of 6 characters, each can be a digit (0–9) or an uppercase letter (A–Z).
Question:
How many possible passwords exist if:
Characters can repeat?
Characters cannot repeat?
*/
#include<stdio.h>

long long power(int n, int r){
    long long result = 1;
    for(int i = 0; i < r; i++){
        result *= n;
    }
    return result;
}

long long select(int n, int r){
    long long result = 1;
    for(int i = 0; i < r; i++){
        result *= (n - i);
    }
    return result;
}

int main(){
    int num = 36, r = 6;

    printf("Without Repetition : %lld\n", power(num, r)); 
    printf("With Repetition : %lld\n", select(num, r));   
}
