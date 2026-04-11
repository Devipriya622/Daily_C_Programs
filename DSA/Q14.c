//Given a list of strings, sort them by their length using any efficient sorting technique.
#include<stdio.h>
#include<string.h>
int main(){
    char *strings[]  = {"abcd","bcd","eg","h"};
    int n= sizeof(strings)/sizeof(strings[0]);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strlen(strings[j])>strlen(strings[j+1])){
                char *temp = strings[j];
                strings[j]=strings[j+1];
                strings[j+1]=temp;
            }
        }
        
    }
    
    for(int i=0;i<n;i++){
        printf("%s ",strings[i]);
    }
    return 0;
}
