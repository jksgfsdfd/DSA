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
    void good(TreeNode* root,int max,int& count){
        if(root==NULL){
            return;
        }
        if(root->val>=max){
            count++;
            good(root->right,root->val,count);
            good(root->left,root->val,count);
            return;
        }
        
        good(root->right,max,count);
        good(root->left,max,count);
        return;
        
    }
    
    int goodNodes(TreeNode* root) {
        int max=INT_MIN;
        int count=0;
        good(root,max,count);
        return count;
    }
};
