//Symmetric Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSymHelp(struct TreeNode* left,struct TreeNode* right){
    if(left == NULL ||right==NULL) return left==right;
    if(left->val!=right->val) return false;
    return isSymHelp(left->left,right->right) && isSymHelp(left->right,right->left);
}
bool isSymmetric(struct TreeNode* root) {
    return root==NULL || isSymHelp(root->left,root->right);
}
