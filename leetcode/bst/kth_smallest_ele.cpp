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
    int find(TreeNode* root,int& count,int k){
        if(root==NULL){
            return -1;
        }
        
        int a=find(root->left,count,k);
        if(count==k){
            return a;
        }
        count++;
        if(count==k){
            return root->val;
        }
        return find(root->right,count,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans = find(root,count,k);
        return ans;
    }
};
