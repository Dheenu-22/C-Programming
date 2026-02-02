#include <string.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int maximumANDSum(int* nums, int numsSize, int numSlots) {
    int maxState = 1;
    for (int i = 0; i < numSlots; i++) maxState *= 3;
    int dp[20000];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int mask = 0; mask < maxState; mask++) {
        if (dp[mask] == -1) continue;
        int used = 0, temp = mask;
        for (int i = 0; i < numSlots; i++) {
            used += temp % 3;
            temp /= 3;
        }
        if (used >= numsSize) continue;
        temp = mask;
        for (int i = 0; i < numSlots; i++) {
            int slotCount = temp % 3;
            if (slotCount < 2) {
                int newMask = mask + (int)pow(3, i);
                dp[newMask] = max(
                    dp[newMask],
                    dp[mask] + (nums[used] & (i + 1))
                );
            }
            temp /= 3;
        }
    }
    int ans = 0;
    for (int i = 0; i < maxState; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}
