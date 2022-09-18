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
    void maketree(TreeNode* root,int start,int end,vector<int>& preorder,vector<int>& inorder,int preorder_index){
        if(start>=end){
            return;
        }
        int index;
        for(index=start;index<=end;index++){
            if(inorder[index]==root->val){
                break;
            }
        }
        if(start==index){
            root->left=NULL;
            root->right=new TreeNode (preorder[preorder_index+index-start+1]);
            maketree(root->right,index+1,end,preorder,inorder,preorder_index+index-start+1);
            return;
        }
        if(end==index){
            root->right=NULL;
            root->left=new TreeNode(preorder[preorder_index+1]);
            maketree(root->left,start,index-1,preorder,inorder,preorder_index+1);
            return;
        }
        root->left=new TreeNode(preorder[preorder_index+1]);
        maketree(root->left,start,index-1,preorder,inorder,preorder_index+1);
        root->right=new TreeNode (preorder[preorder_index+index-start+1]);
        maketree(root->right,index+1,end,preorder,inorder,preorder_index+index-start+1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //check for empty array
        TreeNode* root=new TreeNode(preorder[0]);
        int size=preorder.size();
        int start=0;
        int end=size-1;
        int preorder_index=0;
        maketree(root,start,end,preorder,inorder,preorder_index);
        return root;
    }
};
