//Convert a lowercase string to uppercase without toupper(ASCII arithmetic).
#include<stdio.h>
int main() {
    char str[100];
    printf("Enter a lowercase string (max 99 characters): ");
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A'); 
        }
    }
    
    printf("Uppercase string: %s\n", str);
    
    return 0;
}