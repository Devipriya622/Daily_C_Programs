//Write a function that returns the index of the first occurrence of a substring (naïve).

#include<stdio.h>
#include<string.h>
int findmatch(char *text,char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    
    if(m==0) return 0;
    
    for(int i=0;i<=n-m;i++){
        int j=0;
     while(j<m && text[i+j]==pattern[j]){
         j++;
     }
        if(j==m) return i;
    }
    return -1;
}
int main(){
    char text[200];
    printf("Enter the character : ");
    fgets(text,sizeof(text),stdin);
    char pattern[200];
    printf("Enter the Pattern : ");
    fgets(pattern,sizeof(pattern),stdin);
   int index = findmatch(text,pattern);
    
    if(index ==-1){
        printf("Not found" );
        }else{
            printf("Found at %d",index);
        }
}
