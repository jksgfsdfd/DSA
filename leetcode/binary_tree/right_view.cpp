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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if(root==NULL){
            return answer;
        }
        queue<TreeNode*> parents;
        queue<TreeNode*> childs;
        parents.push(root);
        TreeNode* temp;
        while(!parents.empty()){
            answer.push_back(parents.front()->val);
            //check error
            while(!childs.empty()){
                childs.pop();
            }
            while(!parents.empty()){
                temp=parents.front();
                if(temp->right){
                    childs.push(temp->right);
                }
                if(temp->left){
                    childs.push(temp->left);
                }
                parents.pop();
            }
            parents=childs;
        }
        return answer;
    }
};
