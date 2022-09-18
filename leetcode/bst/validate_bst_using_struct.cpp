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
    struct reply{
        bool ans;
        int min;
        int max;
    };
    
    reply valid (TreeNode* root){
        if(root->right==NULL && root->left==NULL){
            return {true,root->val,root->val};
        }
        
        if(root->right==NULL){
            reply reply_left = valid (root->left);
            if(reply_left.ans==false){
                return {false,-1,-1};
            }
            if(reply_left.max < root->val){
                return {true,reply_left.min,root->val};
            }
            return {false,-1,-1};
        }
        
        if(root->left==NULL){
            reply reply_right = valid (root->right);
            if(reply_right.ans==false){
                return {false,-1,-1};
            }
            if(reply_right.min > root->val){
                return {true,root->val,reply_right.max};
            }
            return {false,-1,-1};
        }
        
        reply reply_left = valid (root->left);
        reply reply_right = valid (root->right);
        if (reply_left.ans==false || reply_right.ans==false){
            return {false,-1,-1};
        }
        
        if (root->val > reply_left.max && root->val < reply_right.min){
            return {true,reply_left.min,reply_right.max};
        }
        
        return {false,-1,-1};
    } 
    
    bool isValidBST(TreeNode* root) {
        reply answer = valid (root);
        if(answer.ans){
            return true;
        }else{
            return false;
        }
    }
};
