//For a circular array A (the element after the last is the first), compute the Next Greater Element for each index using a stack.
#include<stdio.h>

#define N 100000
int stack[N];
int top =-1;

void push(int x){
    if(top<N-1){
        stack[++top] = x;
    }
}

int pop(){
    if(top==-1) return -1;
    return stack[top--];
}

void NextGreater(int n, int arr[]){
    top=-1;
    int nge[n];
    int curr;
    for(int i=0;i<n;i++){
        nge[i]=-1;
    }
    for(int i=2*n-1;i>=0;i--){
        curr = arr[i%n];
        while(top!=-1 && stack[top]<= curr){
            pop();
        }
        if(i<n ){
            if(top!=-1){
            nge[i]= (top==-1)?-1:stack[top];
            }
        }
        push(curr);
    }
    for(int i=0;i<n;i++){
        printf("%d ",nge[i]);
    }
}
int main(){
    int n ;
   
    printf("enter the size of the array: ");
    scanf("%d",&n);
     int arr[n];
    printf("enter the array elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nNext Greater Element II: ");
    NextGreater(n,arr);
}

