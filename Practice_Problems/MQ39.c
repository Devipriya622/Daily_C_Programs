//Flattern Binary Tree to Linked List
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* prev;

void solve(struct TreeNode* root){
    if(root==NULL) return;

    solve(root->right);
    solve(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flatten(struct TreeNode* root) {
    prev = NULL;
    solve(root);
}
