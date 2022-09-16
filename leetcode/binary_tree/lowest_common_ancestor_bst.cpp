/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q){
            return p;
        }
        while(root!=p || root!=q){
            //go till the first difference
            if(p->val > root->val && q->val>root->val){
                root=root->right;
                continue;
            }else if(p->val < root->val && q->val<root->val){
                root=root->left;
                continue;
            }else{
                return root;
            }
        }
        
        return root;
        
    }
};
