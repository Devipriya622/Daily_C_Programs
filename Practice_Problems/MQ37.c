// Recover BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* first,*last,*middle,*prev;
void inorder(struct TreeNode* root){
    if(root==NULL) return ;
    inorder(root->left);
    if(prev!=NULL && (root->val < prev->val)){
        if(first==NULL){
            first = prev;
            middle = root;
        }else{
            last = root;
        }
    }
    prev = root;
    inorder(root->right);
}
void recoverTree(struct TreeNode* root) {
    first = middle = last = prev = NULL;

    inorder(root);

    if(first && last){
        int temp = first->val;
        first->val = last->val;
        last->val = temp;
    }
    else if(first && middle){
        int temp = first->val;
        first->val = middle->val;
        middle->val = temp;
    }
}
