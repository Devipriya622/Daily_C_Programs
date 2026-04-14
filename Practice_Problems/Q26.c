//Sorted Array to Binary Search Tree 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* build(int *nums,int l,int r){
    if(l>r) return NULL;
   int mid = (l+r)/2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = build(nums,l,mid-1);
    node->right = build(nums,mid+1,r);
    return node;
 }
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  return build(nums,0,numsSize-1);
}
