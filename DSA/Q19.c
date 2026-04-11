//Check if two strings are anagrams by comparing their character frequency maps.
Given an array of integers, sort the elements by their frequency in descending order
#include <stdio.h>
#include <string.h>

int isAnagram(char a[], char b[]) {
    int freq[256] = {0};

    for (int i = 0; a[i] != '\0'; i++)
        freq[a[i]]++;

    for (int i = 0; b[i] != '\0'; i++)
        freq[b[i]]--;

    for (int i = 0; i < 256; i++)
        if (freq[i] != 0)
            return 0;

    return 1;
}

void sortByFrequency(int arr[], int n) {
    int freq[1000] = {0};

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (freq[arr[i]] < freq[arr[j]]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2))
        printf("Strings are Anagrams\n");
    else
        printf("Strings are not Anagrams\n");

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array sorted by frequency: ");
    sortByFrequency(arr, n);

    return 0;
}
