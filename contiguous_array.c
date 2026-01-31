#include <stdlib.h>
int findMaxLength(int* nums, int numsSize) {
    int maxLen = 0;
    int sum = 0;
    int hashSize = 2 * numsSize + 1;
    int* map = (int*)malloc(hashSize * sizeof(int));
    for (int i = 0; i < hashSize; i++) map[i] = -2;
    map[numsSize] = -1; 
    for (int i = 0; i < numsSize; i++) {
        sum += (nums[i] == 0 ? -1 : 1);
        int idx = sum + numsSize; 
        if (map[idx] != -2) {
            int len = i - map[idx];
            if (len > maxLen) maxLen = len;
        } else {
            map[idx] = i;
        }
    }
    free(map);
    return maxLen;
}
