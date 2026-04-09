//Given two sorted linked lists, merge them into a single sorted list.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* head, int data){
    struct Node* newNode = createNode(data);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


struct Node* merge(struct Node* l1, struct Node* l2){
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if(l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}


void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n1, n2, x;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter sorted elements for List 1:\n");
    for(int i = 0; i < n1; i++){
        scanf("%d", &x);
        list1 = insert(list1, x);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter sorted elements for List 2:\n");
    for(int i = 0; i < n2; i++){
        scanf("%d", &x);
        list2 = insert(list2, x);
    }

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* merged = merge(list1, list2);

    printf("Merged List: ");
    printList(merged);

    return 0;
}
