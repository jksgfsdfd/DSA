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
    void find_below(vector<int>&answer,TreeNode* target,int k){
        if(target==NULL){
            return;
        }
        if(k==0){
            answer.push_back(target->val);
            return;
        }
        find_below(answer,target->left,k-1);
        find_below(answer,target->right,k-1);
    }
    
    void find_above(vector<int>&answer,vector<TreeNode*>& path,TreeNode* target,int k,int dist_to_target){
        TreeNode* current_node=path.back();
        if(current_node==target){
            return;
        }
        path.pop_back();
        if(k==dist_to_target){
            answer.push_back(current_node->val);
            find_above(answer,path,target,k,dist_to_target-1);
        }else if(k<dist_to_target){
            find_above(answer,path,target,k,dist_to_target-1);   
        }else{
            //find below k-d-1 in the other side of tree
            TreeNode* below_node;
            if(current_node->left==path.back()){
                below_node=current_node->right;
            }else{
                below_node=current_node->left;
            }
            find_below(answer,below_node,k-dist_to_target-1);
            find_above(answer,path,target,k,dist_to_target-1);  
        }
    }
    
    bool find_path(vector<TreeNode*>& path,TreeNode* root,TreeNode* target,int& dist_to_target){
        if(root==target){
            path.push_back(root);
            dist_to_target++;
            return true;
        }
        if(root==NULL){
            return false;
        }
        bool left=find_path(path,root->left,target,dist_to_target);
        bool right=find_path(path,root->right,target,dist_to_target);
        if(left==true or right==true){
            dist_to_target++;
            path.push_back(root);
            return true;
        }
        return false;
    }    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> answer;
        int dist_to_target=0;
        vector<TreeNode*> path;
        
        if(target==root){
            dist_to_target=0;
        }else{
            bool found=find_path(path,root,target,dist_to_target);
            dist_to_target--;
        }
        if(dist_to_target==0){
            find_below(answer,target,k);
        }else{
           find_above(answer,path,target,k,dist_to_target);
           find_below(answer,target,k);
        }
        return answer;
    }
};
