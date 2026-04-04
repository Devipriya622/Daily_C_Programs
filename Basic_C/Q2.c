//Read two integers and print their sum, difference, product, and integer quotient.
#include<stdio.h>
int main(){
    int num1,num2;
    printf("Enter the two integers:");
    scanf("%d %d",&num1,&num2);
    printf("Sum: %d\n",num1+num2);
    printf("Difference: %d\n",num1-num2);
    printf("Product: %d\n",num1*num2);
    if(num2!=0){
        printf("Integer Quotient: %d\n",num1/num2);
    }
    else{
        printf("Cannot divide by zero\n");
    }
    return 0;

}