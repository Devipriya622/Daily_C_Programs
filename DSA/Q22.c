/*Given a Sorted Array and Target ,
return the starting and ending indexes of the target
using binary search
*/
#include <stdio.h>

int firstPos(int arr[], int n, int target){
    int low = 0, high = n - 1;
    int res = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            res = mid;
            high = mid - 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int lastPos(int arr[], int n, int target){
    int low = 0, high = n - 1;
    int res = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            res = mid;
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    int n;
    printf("size: ");
    scanf("%d",&n);

    int arr[n];
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("Enter key: ");
    scanf("%d",&key);

    int start = firstPos(arr, n, key);
    int end = lastPos(arr, n, key);

    if(start == -1){
        printf("Not Found");
    } else {
        printf("Start: %d End: %d", start, end);
    }
}

/*
Find the Peak Element in the array
(an element that is greater than its neighbour) using binary Seacrh in O(logn) time.
*/
#include <stdio.h>

int findPeak(int arr[], int n){
    int low = 0, high = n - 1;

    while(low < high){
        int mid = (low + high) / 2;

        if(arr[mid] < arr[mid + 1]){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int peakIndex = findPeak(arr, n);
    printf("Peak Element Index: %d\n", peakIndex);
    printf("Peak Element Value: %d", arr[peakIndex]);
}
