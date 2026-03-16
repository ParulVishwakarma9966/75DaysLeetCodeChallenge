/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    
    char** keys = (char**)malloc(strsSize * sizeof(char*));
    
    int groupCount = 0;

    for(int i = 0; i < strsSize; i++) {

        char* temp = strdup(strs[i]);
        qsort(temp, strlen(temp), sizeof(char), cmpChar);

        int found = -1;

        for(int j = 0; j < groupCount; j++) {
            if(strcmp(keys[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if(found == -1) {
            keys[groupCount] = temp;
            result[groupCount] = (char**)malloc(strsSize * sizeof(char*));
            result[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            groupCount++;
        } 
        else {
            int index = (*returnColumnSizes)[found];
            result[found][index] = strs[i];
            (*returnColumnSizes)[found]++;
            free(temp);
        }
    }

    *returnSize = groupCount;
    free(keys);

    return result;
}