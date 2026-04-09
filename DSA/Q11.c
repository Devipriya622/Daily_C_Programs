//Given a sorted doubly linked list and a target sum, find all pairs of nodes whose values add up to the target.

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
 struct Node *head=NULL;
 
void insert(int x){
   
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->data = x;
    newNode->next = NULL;
    if(head==NULL){
        head =newNode;
    }else{
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    }
    
}
void findTarget(int target){
    struct Node* left = head;
    struct Node* right = head ;
    while(right->next!=NULL){
        right=right->next;
    }
    if(left==right) {
        printf("Not Possible");
        return ;
    }
    int flag=0;
    printf("Pairs : \n");
    while(left->data<right->data){
        if(((left->data)+(right->data))==target){
            printf("[%d,%d]\n",left->data,right->data);
            left=left->next;
            right=right->prev;
            flag++;
        }else if(((left->data)+(right->data))<target){
            left=left->next;
        }else{
            right=right->prev;
        }
    
    }
    if(flag==0)
    printf("No pair found");
    
}
int main(){
 int n;
 printf("Size: ");
 scanf("%d",&n);
 int x;
 printf("elements: ");
 for(int i=0;i<n;i++){
     scanf("%d",&x);
    insert(x);
 }
 int target ;
 printf("Enter target: ");
 scanf("%d",&target);
 findTarget(target);
}
