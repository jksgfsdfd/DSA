/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        int a = pathSum(root->left,targetSum);
        int b = pathSum(root->right,targetSum);
        int c;int d;
        if(root->left==NULL){
            c = pathSum(root->left,targetSum-root->val);
        }else{
            c = pathSum(root->left,targetSum-root->val) - pathSum(root->left->left,targetSum-root->val) - pathSum(root->left->right,targetSum-root->val);
        }
        if(root->right==NULL){
            d = pathSum(root->right,targetSum-root->val);
        }else{
        d = pathSum(root->right,targetSum-root->val) - pathSum(root->right->left,targetSum-root->val) - pathSum(root->right->right,targetSum-root->val);
        }
        if(root->val==targetSum){
            return (1+a+b+c+d);
        }else{
            return (a+b+c+d);            
        }
    }
};
