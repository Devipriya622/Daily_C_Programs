/*
Design a recursive function to reverse a string without using loops.
Write a recursive version of the binary search algorithm for a sorted array
*/

#include<stdio.h>
#include<string.h>
char *Reverse(char *str,int left ,int right){
  
   if(left>=right) return str;
   
   char temp = str[left];
   str[left] = str[right];
   str[right] = temp;
   
   return Reverse(str,left+1,right-1);
}

int binarySearch(int n,int arr[],int low ,int high,int mid,int key){
    if(low>=high) return mid;
    if(key>=mid) return binarySearch(n,arr,mid+1,high,((mid+1)+high)/2,key);
    else return binarySearch(n,arr,low,mid-1,((mid-1)+high)/2,key);
}

int main(){
    
    printf("String Reverse -> ");
    
    char str1[100];
    
    printf("\nEnter the string : ");
    scanf("%s",str1);
    
    printf("Reversed String is :%s ",Reverse(str1,0,strlen(str1)-1));
    

    printf("\n\nBinary Search ->");
    
    int n;
    printf("\nEnter the size of the Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements in the Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int low = 0;
    int high = n-1;
    int key ;
    
    printf("Enter the key : ");
    scanf("%d",&key);
    
    binarySearch(n,arr,low,high,(low+high)/2,key);
    
    int mid = (low+high)/2;
    if(arr[mid]==key){
        printf("\nFound");
    }else{
        printf("\nNot Found");
    }
}
