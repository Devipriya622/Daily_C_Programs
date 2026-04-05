//Compute the average of an array using pointer arithmetic (no indexing).
#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum = 0;
    for(int *ptr = arr; ptr < arr + n; ptr++){
        sum += *ptr;
    }
    double average = (double)sum / n;
    printf("The average is: %.2lf\n", average);
    return 0;
}