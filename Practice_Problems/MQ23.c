//3Sum

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), cmp);

    int **ans = malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize - 2; i++){

        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int j = i + 1;
        int k = numsSize - 1;

        while(j < k){

            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{

                ans[*returnSize] = malloc(3 * sizeof(int));
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[j];
                ans[*returnSize][2] = nums[k];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                j++;
                k--;

                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }

    return ans;
}
