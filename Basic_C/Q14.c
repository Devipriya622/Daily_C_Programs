//Check if a string is a palindrome (ignore case and non-alphanumeric).
#include<stdio.h>
#include<ctype.h>

int is_palindrome(char str[]) {
    int i = 0, j = 0;
    while (str[j] != '\0') {
        if (isalnum(str[j])) {
            str[i++] = tolower(str[j]);
        }
        j++;
    }
    str[i] = '\0';

    i = 0;
    j = i;
    while (str[j] != '\0') {
        j++;
    }
    j--;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}