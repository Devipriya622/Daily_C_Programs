/*
Write a function to find the maximum product of a contiguous subarray in an array of integers (including negatives and zeros).
Example:
Input: [2, 3, -2, 4]
Output: 6 (subarray [2, 3])
*/
#include<stdio.h>
int maxProduct(int n, int *arr){
    int currMax = arr[0];
    int max = arr[0];
    int pre =1;
    int suff =1;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            pre *= arr[i];
        }else{
            pre =1;
        }
        if(arr[i]!=0){
            suff *=arr[i];
        }else{
            suff =1;
        }
        
        currMax = (pre>suff)?pre:suff;
        max = (currMax>max)?currMax:max;
    }
    return max;
}
int main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int res = maxProduct(n,arr);
    printf("%d is the maximum product " ,res);
}