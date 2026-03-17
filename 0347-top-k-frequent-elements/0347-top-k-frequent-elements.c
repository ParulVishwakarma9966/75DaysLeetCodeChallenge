/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;


int cmpNum(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


int cmpFreq(const void* a, const void* b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
   
    qsort(nums, numsSize, sizeof(int), cmpNum);

    
    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    int index = 0;

    for(int i = 0; i < numsSize; ) {
        int count = 1;
        int val = nums[i];

        while(i + 1 < numsSize && nums[i] == nums[i+1]) {
            count++;
            i++;
        }

        arr[index].num = val;
        arr[index].freq = count;
        index++;
        i++;
    }

    
    qsort(arr, index, sizeof(Pair), cmpFreq);

    
    int* result = (int*)malloc(k * sizeof(int));

    for(int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}