#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define N 100

int stack[N];
int top = -1;

void push(int val){
    stack[++top] = val;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main(){
    
    char exp[100];
    printf("Enter RPN expression : ");
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while(token != NULL){

        if(isdigit(token[0])){
            push(atoi(token));
        }
        else{
            int op2 = pop();
            int op1 = pop();
            int result;

            switch(token[0]){
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if(op2 == 0){
                        printf("Division by zero error\n");
                        return 1;
                    }
                    result = op1 / op2; 
                    break;
                case '^': result = (int)pow(op1, op2); break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("Result = %d\n", pop());
}