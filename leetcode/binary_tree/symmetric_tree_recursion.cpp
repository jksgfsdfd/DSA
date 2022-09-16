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
    bool findans (TreeNode* left,TreeNode* right){
        if(left==NULL || right==NULL){
            if(left==right){
                return true;
            }else{
                return false;
            }
        }
        if(left->val!=right->val){
            return false;
        }
        bool ans1 = findans(left->left,right->right);
        bool ans2 = findans(left->right,right->left);
        if(ans1==false || ans2==false){
            return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        bool answer;
        if(root==NULL){
            return true;
        }
        
        answer = findans(root->left,root->right);
        return answer;
    }
};
