/*Given a catalog of product names across languages (ASCII + Unicode—accents, diacritics), group names that are anagrams after normalization (case folding, NFKD/NFC handling, accent removal).*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str1[100], str2[100];
    int arr[26] = {0};

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    if(strlen(str1) != strlen(str2))
    {
        printf("Not anagram\n");
        return 0;
    }

    for(int i=0;i<strlen(str1);i++)
    {
        char c = tolower(str1[i]);
        arr[c - 'a']++;
    }

    for(int i=0;i<strlen(str2);i++)
    {
        char c = tolower(str2[i]);
        arr[c - 'a']--;
    }

    for(int i=0;i<26;i++)
    {
        if(arr[i] != 0)
        {
            printf("Not anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");

    return 0;
}
