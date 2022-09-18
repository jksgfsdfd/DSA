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
    
    void dfs(TreeNode* root,bool must_include){
        if(root==NULL){
            return;
        }
        if(must_include){
            currentlist.push_back(root->val);
            answer.push_back(currentlist);
            dfs(root->left,true);
            dfs(root->right,true);
            currentlist.pop_back();
        }else{
            currentlist.push_back(root->val);
            answer.push_back(currentlist);
            dfs(root->left,true);
            dfs(root->right,true);
            currentlist.pop_back();
            
            dfs(root->left,false);
            dfs(root->right,false);
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,false);
        for(auto path : answer){
            for(int val : path){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};
