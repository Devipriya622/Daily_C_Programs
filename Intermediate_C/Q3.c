//Implement strcpy safely (bounded copy) and discuss buffer overflow risks.

#include <stdio.h>
void safe_strcpy(char *dest, const char *src, int dest_size) {
    int i;

    for (i = 0; i <= dest_size - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';
}
int main() {
    char dest[5];          
    char src[] = "Hello";  

    safe_strcpy(dest, src, 5); 

    printf("Copied string: %s\n", dest);  
}
