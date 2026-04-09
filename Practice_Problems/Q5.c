/*Two Sum */
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
 * Complete the 'findTaskPairForSlot' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY taskDurations
 *  2. INTEGER slotLength
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
 *
*
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
typedef struct {
    int value;
    int index;
} Pair;

int cmp(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int* findTaskPairForSlot(int n, int* taskDurations, int slotLength, int* result_count) {
    *result_count = 2;
    int* result = malloc(2 * sizeof(int));
    if (n < 2) {
        result[0] = result[1] = -1;
        return result;
    }

    Pair* arr = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        arr[i].value = taskDurations[i];
        arr[i].index = i;
    }

    qsort(arr, n, sizeof(Pair), cmp);

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left].value + arr[right].value;
        if (sum == slotLength) {
            result[0] = arr[left].index;
            result[1] = arr[right].index;
            free(arr);
            return result;
        } else if (sum < slotLength) {
            left++;
        } else {
            right--;
        }
    }

    result[0] = result[1] = -1;
    free(arr);
    return result;
}
int main()
{
    int taskDurations_count = parse_int(ltrim(rtrim(readline())));

    int* taskDurations = malloc(taskDurations_count * sizeof(int));

    for (int i = 0; i < taskDurations_count; i++) {
        int taskDurations_item = parse_int(ltrim(rtrim(readline())));

        *(taskDurations + i) = taskDurations_item;
    }

    int slotLength = parse_int(ltrim(rtrim(readline())));

    int result_count;
    int* result = findTaskPairForSlot(taskDurations_count, taskDurations, slotLength, &result_count);

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
