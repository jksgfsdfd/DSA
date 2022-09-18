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
    vector<string> answer;
    vector<int> currentlist;
    
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            currentlist.push_back(root->val);
            string s;
            for(int i=0;i<currentlist.size()-1;i++){
                s+=to_string(currentlist[i]);
                s+="->";
            }
            s+=to_string(currentlist.back());
            answer.push_back(s);
            currentlist.pop_back();
            return;
        }
        currentlist.push_back(root->val);
        
        dfs(root->left);
        dfs(root->right);
        currentlist.pop_back();
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return answer;
    }
};
