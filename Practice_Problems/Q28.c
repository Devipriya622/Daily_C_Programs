//PreOrder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void preorderHelper(struct TreeNode* root,int* result,int* index){
    if(root==NULL) return;
    result[(*index)++]= root->val;
    preorderHelper(root->left,result,index);
    preorderHelper(root->right,result,index);
    
 }
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(sizeof(int)*1000);
    *returnSize =0;
    preorderHelper(root,result,returnSize);
    return result;
}
