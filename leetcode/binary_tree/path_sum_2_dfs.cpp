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
    vector<vector<int>>answer;
    vector<int> currentlist;
    int sum = 0;
    
    void dfs(TreeNode* root,const int & targetSum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            currentlist.push_back(root->val);
            if(sum==targetSum){
                answer.push_back(currentlist);
            }
            sum-=root->val;
            currentlist.pop_back();
            return;
        }
        currentlist.push_back(root->val);
        sum+=root->val;
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        sum-=root->val;
        currentlist.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return answer;
        }
        dfs(root,targetSum);
        return answer;
    }
};
