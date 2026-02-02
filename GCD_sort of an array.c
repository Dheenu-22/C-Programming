#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 100001
int parent[MAXV];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
bool gcdSort(int* nums, int numsSize) {
    for (int i = 0; i < MAXV; i++)
        parent[i] = i;
    int spf[MAXV];
    for (int i = 0; i < MAXV; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAXV; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXV; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        while (x > 1) {
            int p = spf[x];
            unite(nums[i], p);
            while (x % p == 0)
                x /= p;
        }
    }
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    memcpy(sorted, nums, numsSize * sizeof(int));
    qsort(sorted, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (find(nums[i]) != find(sorted[i])) {
            free(sorted);
            return false;
        }
    }
    free(sorted);
    return true;
}
