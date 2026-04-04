//Remove all occurrences of a given character from a string in-place.
#include<stdio.h>
int main() {
    char str[100], ch;
    printf("Enter a string (max 99 characters): ");
    fgets(str, sizeof(str), stdin);
    
    printf("Enter the character to remove: ");
    scanf("%c", &ch);
    
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; 
    
    printf("String after removing '%c': %s\n", ch, str);
    
    return 0;
}