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
    pair<bool,int> depth(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        pair<bool,int> right_depth=depth(root->right);
        pair<bool,int> left_depth=depth(root->left);
        if(right_depth.first==false || left_depth.first==false){
            return {false,-1};
        }
        if(abs(right_depth.second-left_depth.second)>1){
            return {false,-1};
        }
        if(right_depth.second>left_depth.second){
            return {true,right_depth.second+1};
        }else{
            return {true,left_depth.second+1};
        }
    }
    
    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans = depth(root);
        return ans.first;
    }
};
