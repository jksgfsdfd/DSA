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
    TreeNode* prev_ele=NULL;
    TreeNode* big_ele=NULL;
    TreeNode* small_ele=NULL;
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(prev_ele!=NULL){
            if(root->val<prev_ele->val){
                if(big_ele==NULL){
                    big_ele = prev_ele;
                }
                small_ele=root;
            }
        }
        prev_ele=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        int temp = big_ele->val;
        big_ele->val=small_ele->val;
        small_ele->val=temp;
        
    }
};
