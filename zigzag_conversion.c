#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* convert(char* s, int numRows) {
    if (numRows == 1) return strdup(s); // Special case
    int len = strlen(s);
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowLen = (int*)calloc(numRows, sizeof(int));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
        rows[i][0] = '\0';
    }
    int curRow = 0;
    int goingDown = 0;
    for (int i = 0; i < len; i++) {
        int l = rowLen[curRow];
        rows[curRow][l] = s[i];
        rows[curRow][l + 1] = '\0';
        rowLen[curRow]++;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }
    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }
    free(rows);
    free(rowLen);
    return result;
}
