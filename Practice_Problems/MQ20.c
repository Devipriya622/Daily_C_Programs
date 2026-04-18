//ZigZag Conversion
char* convert(char* s, int numRows) {
    int n = strlen(s);
    if(numRows == 1 || numRows >= n)
        return s;

    char **rows = (char**)malloc(numRows * sizeof(char*));
    int *sizes = (int*)calloc(numRows, sizeof(int));

    for(int i = 0; i < numRows; i++)
        rows[i] = (char*)malloc((n+1) * sizeof(char));

    int currentRow = 0;
    int goingDown = 0;

    for(int i = 0; i < n; i++) {

        rows[currentRow][sizes[currentRow]++] = s[i];

        if(currentRow == 0 || currentRow == numRows-1)
            goingDown = !goingDown;

        currentRow += goingDown ? 1 : -1;
    }

    char *result = (char*)malloc((n+1) * sizeof(char));
    int pos = 0;

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < sizes[i]; j++)
            result[pos++] = rows[i][j];
    }

    result[pos] = '\0';
    return result;
}
