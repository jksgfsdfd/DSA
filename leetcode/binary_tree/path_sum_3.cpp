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
    vector<vector<int>> answer;
    vector<int> currentlist;
    long long int sum=0;
    int count = 0;
    
    
    void dfs(TreeNode* root,bool must_include,int& targetSum){
        if(root==NULL){
            return;
        }
        if(must_include){
            //currentlist.push_back(root->val);
            sum+=root->val;
            if(sum==targetSum){
                count++;
            }
            //answer.push_back(currentlist);
            dfs(root->left,true,targetSum);
            dfs(root->right,true,targetSum);
            //currentlist.pop_back();
            sum-=root->val;
        }else{
            //currentlist.push_back(root->val);
            //answer.push_back(currentlist);
            sum+=root->val;
            if(sum==targetSum){
                count++;
            }
            dfs(root->left,true,targetSum);
            dfs(root->right,true,targetSum);
            //currentlist.pop_back();
            sum-=root->val;
            dfs(root->left,false,targetSum);
            dfs(root->right,false,targetSum);
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,false,targetSum);
        return count;
    }
};
