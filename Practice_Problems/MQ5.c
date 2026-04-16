//Max Unique Substring Length in a Session
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



/*
 * Complete the 'maxDistinctSubstringLengthInSessions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING sessionString as parameter.
 */

int maxDistinctSubstringLengthInSessions(char* sessionString) {
int visited[26] = {0};
    int left = 0, maxLen = 0;

    for (int right = 0; sessionString[right] != '\0'; right++) {

        if (sessionString[right] == '*') {
            for (int i = 0; i < 26; i++) visited[i] = 0;
            left = right + 1;
            continue;
        }

        int idx = sessionString[right] - 'a';

        while (visited[idx]) {
            visited[sessionString[left] - 'a'] = 0;
            left++;
        }

        visited[idx] = 1;

        int currLen = right - left + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}

int main()
{
    char* sessionString = readline();

    int result = maxDistinctSubstringLengthInSessions(sessionString);

    printf("%d\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
