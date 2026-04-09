/*write an algorithm to find an element 
in a rotated sorted array using an efficient searching technique*/

#include<stdio.h>
#include<stdbool.h>
int findminIndex(int n,int arr[]){
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[j])
        return i;
    }
}
int sort(int n,int arr[],int key){
    int minIndex = findminIndex(n,arr);
    for(int i=0;i<n;i++){
        if(arr[i%n]==key)
          return (i-minIndex + n)%n;
    }
    return -1;
}

int main(){
    int n;
    printf("Size of the Array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("enter the key:");
    scanf("%d",&key);
    int result = sort(n,arr,key);
    if(result!=-1){
        printf("Element found at %d ",result);
        }else{
            printf("Element not found");
        }
}
















