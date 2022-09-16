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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        vector<TreeNode*> parents;
        vector<TreeNode*> childs;
        if(root==NULL){
            return answer;
        }
        childs.push_back(root);
        vector<int> child_vals;
        child_vals.clear();
        for(auto ele : childs){
            child_vals.push_back(ele->val);
        }
        answer.push_back(child_vals);
        parents.clear();
        
        while(!childs.empty()){
            parents=childs;
            childs.clear();
            for(auto ele : parents){
                if(ele->left){
                    childs.push_back(ele->left);
                }
                if(ele->right){
                    childs.push_back(ele->right);
                }
            }
            child_vals.clear();
            if(childs.empty()){
                return answer;
            }
            for(auto ele : childs){
                child_vals.push_back(ele->val);
            }
            answer.push_back(child_vals);
            parents.clear();
        }
        
        return answer;
    }
};
