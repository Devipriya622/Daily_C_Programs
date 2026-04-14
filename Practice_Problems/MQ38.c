//Validate Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isvalid(struct TreeNode* root,long long min,long long max){
    if(root==NULL) return true;
    if(root->val <= min || root->val >=max) return false;
    return isvalid(root->left,min,root->val)&& isvalid(root->right,root->val,max);
    return true;
}
bool isValidBST(struct TreeNode* root) {
   return isvalid(root,LLONG_MIN,LLONG_MAX);
}
