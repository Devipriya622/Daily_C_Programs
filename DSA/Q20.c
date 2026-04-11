//Given a log file with event types (e.g., INFO, WARN, ERROR), count the frequency of each event type and identify the most common one.

#include<stdio.h>
#include<string.h>
#define MAX 100
int main(){
    char logs[MAX][10];
    int n;
    printf("Enter no.of log entries: ");
    scanf("%d",&n);
    printf("Enter Log Types (Info/warn/Error ): \n");
    for(int i=0;i<n;i++){
        scanf("%s",logs[i]);
    }
    int info =0,warn =0,error =0;
    for(int i=0;i<n;i++){
        if(strcmp(logs[i], "INFO") == 0||strcmp(logs[i], "info") == 0)
        info++;
        else if(strcmp(logs[i], "WARN")==0||strcmp(logs[i], "warn")==0)
        warn++;
        else if(strcmp(logs[i], "ERROR")==0||strcmp(logs[i], "error")==0)
        error++;
    }
    
    printf("INFO : %d\n",info);
     printf("WARN : %d\n",warn);
      printf("ERROR : %d\n",error);

    if(info>=warn && info>=error)
    printf("Most Common : INFO\n");
    else if (warn>=info && warn >=error)
    printf("Most Common : WARN\n");
    else 
    printf("Most Common : ERROR\n");
    return 0;
}

//Given a list of product IDs, use frequency counting to find which IDs appear more than once.
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of products: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter product IDs:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nDuplicate Product IDs:\n");

    for(int i = 0; i < n; i++) {
        int count = 1;

        int visited = 0;
        for(int k = 0; k < i; k++) {
            if(arr[i] == arr[k]) {
                visited = 1;
                break;
            }
        }
        if(visited) continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count > 1) {
            printf("%d appears %d times\n", arr[i], count);
        }
    }

    return 0;
}

