//Binary Tree Level Order Traversal
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
if(root==NULL){
    *returnSize =0;
    return NULL;
}
struct TreeNode *queue[2000];
int front =0;
int rear=0;
int **result = (int**)malloc(sizeof(int*)*2000);
*returnColumnSizes = (int*)malloc(sizeof(int)*2000);

queue[rear++] = root;
*returnSize =0;

while(front<rear){
    
    int levelSize = rear-front ;
    (*returnColumnSizes)[*returnSize] = levelSize;
    result[*returnSize] = (int*)malloc(sizeof(int) * levelSize);
    
    int i=0;
   while(levelSize--){

    struct TreeNode *node = queue[front++];

    result[*returnSize][i++]=node->val;

    if(node->left!=NULL){
   queue[rear++]=node->left;
    }
    if(node->right!=NULL){
        queue[rear++]=node->right;
    }
   
   }
    (*returnSize)++;
}
return result;
}
