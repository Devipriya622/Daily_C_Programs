//Given a string of brackets like "({[]})", use a list as a stack to determine if the string is balanced.
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define N 100
int stack[N];
int top =-1;
void push(char s){
    stack[++top]=s;
}
char pop(){
  return  stack[top--];
}
bool isbalanced(char str[]){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            push(str[i]);
        }else{
            if(top==-1){
                return false;
            }else{
                char ch = pop();
                if((str[i]==')'&& ch!='(')||
                (str[i]==']'&& ch !='[')||
                (str[i]=='}'&&ch!='{')){
                    return false;
                }
               
            }
        }
    }
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
int main(){
    char str[100];
    printf("enter the expression:");
    scanf("%s",&str);
    if(isbalanced(str)){
        printf("True");
    }else{
        printf("False");
    }
}
