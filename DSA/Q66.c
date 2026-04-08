/* Create a sequence of length n where:

Odd positions contain increasing positive integers
Even positions contain decreasing negative integers
Example:
Input: n = 6
Output: [1, -1, 2, -2, 3, -3]
*/

#include<stdio.h>

int main(){
    int n;
    printf("Enter the Size of the Array: ");
    scanf("%d",&n);
    
    int arr[n];
    
    int k =1 ;
    
    for(int i=0;i<n;i++){
        if(i%2==0)
       {
           arr[i] = k;
       }else{
           arr[i] = -k;
           k++;
       }
      
    }
    
    printf("Sequence : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
   
}
