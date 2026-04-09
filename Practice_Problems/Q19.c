// Length of Last Word
int lengthOfLastWord(char* s) {
    int right = strlen(s)-1;
    int cnt =0;
    while(right>=0 && s[right]==' '){
        right--;
    }
    while(right>=0 && isalpha(s[right])){
        right--;
        cnt++;
    }
    return cnt;
}
