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
    //check if children of right tree is equal to left...else flip and check 
    bool find_flip(TreeNode* parent_left, TreeNode* parent_right){
        TreeNode* left_left=parent_left->left;
        TreeNode* left_right=parent_left->right;
        TreeNode* right_left=parent_right->left;
        TreeNode* right_right=parent_right->right;
        TreeNode* temp;
        if(left_left==NULL and left_right==NULL){
            if(right_left==NULL and right_right==NULL){
                return true;
            }else{
                return false;
            }
        }
        if(right_left==NULL and right_right==NULL){
            return false;
        }
        if(left_left==NULL){
            if(right_left==NULL){
                if(left_right->val==right_right->val){
                    return find_flip(left_right,right_right);
                }else{
                    return false;
                }
            }else if(right_right==NULL){
                if(left_right->val==right_left->val){
                    return find_flip(left_right,right_left);
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        
        if(left_right==NULL){
            if(right_left==NULL){
                if(left_left->val==right_right->val){
                    return find_flip(left_left,right_right);
                }else{
                    return false;
                }
            }else if(right_right==NULL){
                if(left_left->val==right_left->val){
                    return find_flip(left_left,right_left);
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        
        if(right_left==NULL or right_right==NULL){
            return false;
        }
        
        if(left_left->val!=right_left->val){
            temp=right_right;
            right_right=right_left;
            right_left=temp;
        }
        
        if(left_left->val!=right_left->val or left_right->val!=right_right->val){
            return false;
        }else{
            bool result1=find_flip(left_left,right_left);
            bool result2=find_flip(left_right,right_right);
            if(result1==true and result2==true){
                return true;
            }else{
                return false;
            }
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL or root2==NULL){
            if(root1!=root2){
                return false;
            }else{
                return true;
            }
        }
        if(root1->val!=root2->val){
            return false;
        }
        bool answer=find_flip(root1,root2);
        return answer;
    }
};
