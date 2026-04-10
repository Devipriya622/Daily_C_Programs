//Multiply Strings
char* multiply(char* num1, char* num2) {

    if(num1[0]=='0' || num2[0]=='0'){
        char *r = malloc(2);
        strcpy(r,"0");
        return r;
    }

    int n1 = strlen(num1);
    int n2 = strlen(num2);

    int *res = calloc(n1+n2,sizeof(int));

    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            int mul=(num1[i]-'0')*(num2[j]-'0');
            int sum=mul+res[i+j+1];

            res[i+j+1]=sum%10;
            res[i+j]+=sum/10;
        }
    }

    char *ans = malloc(n1+n2+1);
    int i=0,k=0;

    if(res[0]==0)
        i=1;

    for(;i<n1+n2;i++)
        ans[k++]=res[i]+'0';

    ans[k]='\0';

    free(res);
    return ans;
}
