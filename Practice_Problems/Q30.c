//Excel Sheet Column Title
char* convertToTitle(int columnNumber) {
    char* result = (char*)malloc(10 * sizeof(char));
    int index = 0;

    while(columnNumber>0){
       columnNumber--;
       int rem = columnNumber%26;
       result[index++] = 'A'+rem;
       columnNumber /=26;
    }
     for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    result[index] = '\0';
    return result;
}
