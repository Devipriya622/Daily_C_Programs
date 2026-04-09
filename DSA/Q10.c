//Given a circular linked list, split it into two equal halves (or nearly equal if odd length).
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    
    if(head == NULL){
        head = newnode;
        newnode->next = head;
    } else {
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void split(){
    if(head == NULL || head->next == head){
        printf("NOT VALID");
        return;
    }

    struct node *slow = head;
    struct node *fast = head;


    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    
    if(fast->next->next == head){
        fast = fast->next;
    }

    struct node *head1 = head;
    struct node *head2 = slow->next;

    slow->next = head1;

    
    fast->next = head2;


    printf("First half: ");
    struct node *temp = head1;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head1);

    printf("\nSecond half: ");
    temp = head2;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head2);
}

int main(){
    int n;
    printf("Size: ");
    scanf("%d",&n);

    int x;
    printf("Elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        insert(x);
    }

    split();
}
