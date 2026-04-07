//string,pattern matching, KMP algorithm

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *getlps(char *pattern){
    int len = strlen(pattern);
    int *lps = (int*)malloc(sizeof(strlen(pattern)));
    for(int i=0;i<len;i++){
        lps[i]=0;
    }
    int j=0;
    for(int i=1;i<len;i++){
        if(pattern[j]==pattern[i]){
            j++;
            lps[i]= j;
        }else{
            if(j==0){
            continue;
            }else{
                j=lps[j-1];
                i--;
            }
        }
    }
    for(int i=0;i<len;i++){
        printf("%d ",lps[i]);
    }
    return lps;
}
void Kmp(char *str,char *pattern){
    int j=0;
    int *lps = getlps(pattern);
    for(int i=0;i<strlen(str);i++){
        if(str[i]==pattern[j]){
            j++;
        }else{
            if(j==0){
                continue;
            }else{
                j=lps[j-1];
                i--;
            }
        }
        if(j==strlen(pattern)){
            printf("\n%d found",i-j+1);
        }
    }
}
int main(){
    char str[100];
    printf("Enter string: ");
    scanf("%s",str);
    char pattern[100];
    printf("Enter pattern: ");
    scanf("%s",pattern);
    Kmp(str,pattern);
    
}