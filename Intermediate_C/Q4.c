//Write a program to merge two sorted arrays into a single sorted output.
#include<stdio.h>
void merge(int a[], int n, int b[], int m, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }

    while (i < n) {
        result[k++] = a[i++];
    }
    while (j < m) {
        result[k++] = b[j++];
    }
}
int main(){
    int n,m;
    printf("Enter n and m : ");
    scanf("%d%d",&n,&m);
    int arr1[n];
    int arr2[m];
    printf("Enter the sorted array1 : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the sorted array2 : ");
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
     int result[n + m];
      merge(arr1, n,arr2, m, result);

    printf("Merged array: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", result[i]);
    }

}
