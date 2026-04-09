//Longest Common Prefix
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0) return strdup("");
    if(strsSize==1) return strdup(strs[0]);
    
    char *prefix = strs[0];
    int prefixlen = strlen(prefix);
    for(int i=1;i<strsSize;i++){
        int j=0;
       while(j<prefixlen && strs[i][j] && strs[i][j]==prefix[j]){
        j++;
       }
       prefixlen =j;
       prefix[prefixlen] = '\0';
       if(prefixlen==0) break;
    }
    return prefix;
}
