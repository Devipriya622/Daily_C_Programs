//Read a string (with spaces) safely and print its length without using strlen.
#include<stdio.h>
int main() {
    char str[100];
    printf("Enter a string (max 99 characters): ");
    fgets(str, sizeof(str), stdin);
    
    int length = 0;
    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    
    printf("Length of the string: %d\n", length);
    
    return 0;
}