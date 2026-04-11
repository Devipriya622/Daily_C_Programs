//Given an array and a window size k, use a deque to find the maximum element in each sliding window.
#include <stdio.h>
#include <stdlib.h>

void slidingWindowMax(int arr[], int n, int k) {

    int dq[n];
    int front = 0, back = -1;

    for (int i = 0; i < n; i++) {
        if (front <= back && dq[front] <= i - k)
            front++;

        while (front <= back && arr[dq[back]] <= arr[i])
            back--;

        dq[++back] = i;

        if (i >= k - 1)
            printf("%d ", arr[dq[front]]);
    }

}

int main() {
    int n, k;
    printf("Enter Size of the Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Array Elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter Window Size: ");
    scanf("%d", &k);
    printf("\n Maximum Element in each window : ");
    slidingWindowMax(arr, n, k);

    return 0;
}
