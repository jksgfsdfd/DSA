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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        if(root==NULL){
            return true;
        }
        left.push(root->left);
        right.push(root->right);
        
        while(!left.empty()){
            TreeNode* left_ele = left.front();
            TreeNode* right_ele = right.front();
            
            if(left_ele==NULL || right_ele==NULL){
                if(left_ele!=right_ele){
                    return false;
                }
                left.pop();
                right.pop();
                continue;
            }
            
            if(left_ele->val!=right_ele->val){
                return false;
            }
            
            left.pop();
            right.pop();
            
            left.push(left_ele->left);
            left.push(left_ele->right);
            right.push(right_ele->right);
            right.push(right_ele->left);
        }
        
        return true;
    }
};
