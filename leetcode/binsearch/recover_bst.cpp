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
    void inorder(vector<pair<int,TreeNode*>>& curr,TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(curr,root->left);
        curr.push_back({root->val,root});
        inorder(curr,root->right);
    }
    
    void recoverTree(TreeNode* root) {
        vector<pair<int,TreeNode*>> curr;
        inorder(curr,root);
        int index_big=-1;
        int index_small=-1;
        for(auto ele : curr){
            cout<<ele.first<<" ";
        }
        for(int i=0;i<curr.size()-1;i++){
            if(curr[i].first>curr[i+1].first){
                if(index_big==-1){
                    index_big=i;
                }else{
                    index_small=i+1;
                }
            }
            
        }
        if(index_small==-1){
            index_small=index_big+1;
        }
        int temp = curr[index_big].second->val;
        curr[index_big].second->val=curr[index_small].second->val;
        curr[index_small].second->val= temp;
    }
};
