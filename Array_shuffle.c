#include <stdlib.h>
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        res[idx++] = nums[i];      
        res[idx++] = nums[i + n];   
    }
    *returnSize = numsSize;
    return res;
}
