//Maximum Depth of the Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max(int a,int b){
return (a>b)?a:b;
 }
int maxDepth(struct TreeNode* root) {
    struct TreeNode* node = root;
    if(root==NULL) return 0;
    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);

    return 1+max(lh,rh);
}
