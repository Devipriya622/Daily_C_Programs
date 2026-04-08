/*From a group of 12 players, you need to select a team of 5 players.
Question:
How many ways can you choose the team?
How many ways if one specific player must be included?
*/
#include<stdio.h>

long long fact(int n){
    long long f = 1;
    for(int i = 1; i <= n; i++){
        f = f * i;
    }
    return f;
}

long long nCr(int n, int r){
    return fact(n) / (fact(r) * fact(n - r));
}

int main(){
    int n = 12, r = 5;

    printf("%lld\n", nCr(n, r));
    printf("%lld", nCr(n - 1, r - 1));

    return 0;
}
