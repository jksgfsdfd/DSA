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
    vector<int> current_path;
    vector<vector<int>> answer;
    
    void hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(root->val==targetSum){
                current_path.push_back(root->val);
                answer.push_back(current_path);
                current_path.pop_back();
                return;
            }else{
                return ;
            }
        }
        
        if(root->left==NULL){
            current_path.push_back(root->val);
            hasPathSum(root->right,targetSum-root->val);
            current_path.pop_back();
            return;
        }
        
        if(root->right==NULL){
            current_path.push_back(root->val);
            hasPathSum(root->left,targetSum-root->val);
            current_path.pop_back();
            return;
        }
        
        current_path.push_back(root->val);
        hasPathSum(root->left,targetSum-root->val);
        hasPathSum(root->right,targetSum-root->val);
        current_path.pop_back();
        return ;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        hasPathSum(root,targetSum);
        return answer;
    }
};
