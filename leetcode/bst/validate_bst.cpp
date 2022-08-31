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
    pair<bool,pair<int,int>> valid(TreeNode* root){
        if(root->left==NULL and root->right==NULL){
            return {true,{root->val,root->val}};
        }else if(root->left==NULL){
            pair result1=valid(root->right);
            if(result1.first==false){
                return {false,{-1,-1}};
            }else if(root->val>=result1.second.second){
                return {false,{-1,-1}};
            }else{
                return{true,{result1.second.first,root->val}};
            }
        }else if(root->right==NULL){
            pair result2=valid(root->left);
            if(result2.first==false){
                return {false,{-1,-1}};
            }else if(root->val<=result2.second.first){
                return {false,{-1,-1}};
            }else{
                return{true,{root->val,result2.second.second}};
            }
        }
        
        pair result1=valid(root->right);
        pair result2=valid(root->left);
        
        if(result1.first==false or result2.first==false){
            return {false,{-1,-1}};
        }
        
        if(root->val>=result1.second.second){
            return {false,{-1,-1}};
        }else if(root->val<=result2.second.first){
            return {false,{-1,-1}};
        }
        
        return{true,{result1.second.first,result2.second.second}};
    }
    
public:
    bool isValidBST(TreeNode* root) {
        pair<bool,pair<int,int>> result=valid(root);
        return result.first;
    }
};
