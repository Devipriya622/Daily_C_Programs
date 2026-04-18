//Minimum Operations to Convert to Zero

int minOperations(int* nums, int numsSize) {

    int *stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    int operations = 0;

    for(int i = 0; i < numsSize; i++) {

        if(nums[i] == 0){
            top = -1;
            continue;
        }

        while(top >= 0 && stack[top] > nums[i])
            top--;

        if(top < 0 || stack[top] < nums[i]) {
            operations++;
            stack[++top] = nums[i];
        }
    }

    free(stack);
    return operations;
}
