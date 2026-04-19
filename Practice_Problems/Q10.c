//Min-Tracking Stack Implementation
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
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'processCouponStackOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* processCouponStackOperations(int operations_count, char** operations, int* result_count) {
 int *stack = (int*)malloc(operations_count * sizeof(int));
    int *minStack = (int*)malloc(operations_count * sizeof(int));

    int top1 = -1, top2 = -1;

    int *result = (int*)malloc(operations_count * sizeof(int));
    int idx = 0;

    for (int i = 0; i < operations_count; i++) {

        if (operations[i][0] == 'p' && operations[i][1] == 'u') {
            int x;
            sscanf(operations[i], "push %d", &x);

            stack[++top1] = x;

            if (top2 == -1 || x <= minStack[top2]) {
                minStack[++top2] = x;
            } else {
                minStack[++top2] = minStack[top2];
            }
        }

        else if (operations[i][0] == 'p' && operations[i][1] == 'o') {
            top1--;
            top2--;
        }

        else if (operations[i][0] == 't') {
            result[idx++] = stack[top1];
        }

        else { 
            result[idx++] = minStack[top2];
        }
    }

    *result_count = idx;
    return result;
}

int main()
{
    int operations_count = parse_int(ltrim(rtrim(readline())));

    char** operations = malloc(operations_count * sizeof(char*));

    for (int i = 0; i < operations_count; i++) {
        char* operations_item = readline();

        *(operations + i) = operations_item;
    }

    int result_count;
    int* result = processCouponStackOperations(operations_count, operations, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf("\n");
        }
    }

    printf("\n");

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

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
