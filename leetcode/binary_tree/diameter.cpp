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
    int depth(TreeNode* root,int& max){
        if(root==NULL){
            return 0;
        }
        int left_depth=depth(root->left,max);
        int right_depth=depth(root->right,max);
        if(left_depth+right_depth+1>max){
            max=left_depth+right_depth+1;
        }
        if(left_depth>right_depth){
            return (left_depth+1);
        }else{
            return (right_depth+1);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int max=INT_MIN;
        int height=depth(root,max);
        return (max-1);
    }
};
