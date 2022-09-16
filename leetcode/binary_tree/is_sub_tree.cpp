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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            if(p==q){
                return true;
            }else{
                return false;
            }
        }
        if(p->val!=q->val){
            return false;
        }
        return (isSameTree(p->right,q->right) && isSameTree(p->left,q->left));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        //check if same tree for all nodes
        if(root==NULL){
            return false;
        }
        if(isSameTree(root,subroot)){
            return true;
        }
        return (isSubtree(root->left,subroot) || isSubtree(root->right,subroot));
    }
};
