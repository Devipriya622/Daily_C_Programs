/*Given an array of integers, build a prefix sum array where each element at index i is the sum of all elements from 0 to i.
Example:
Input: [2, 4, 6, 8]
Output: [2, 6, 12, 20]
*/
#include<stdio.h>
void prefixSum(int n,int arr[]){
    int pre[n];
    
    pre[0]= arr[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    printf("Prefix Sum Array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",pre[i]);
    }
}
int main(){
    int n;
    printf("Enter the size of the Array :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements in the Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    prefixSum(n,arr);
    return 0;
}
