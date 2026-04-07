//Given a string, compress it by replacing consecutive repeating characters with the character followed by its count (e.g., "aaabb" → "a3b2")
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int count;

    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        count = 1;

        while(i < len - 1 && str[i] == str[i+1])
        {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
    }

    return 0;
}
