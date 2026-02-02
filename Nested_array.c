int arrayNesting(int* nums, int numsSize) {
    int maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == -1) continue;
        int count = 0;
        int curr = i;
        while (nums[curr] != -1) {
            int next = nums[curr];
            nums[curr] = -1;  
            curr = next;
            count++;
        }
        if (count > maxLen) {
            maxLen = count;
        }
    }
    return maxLen;
}
