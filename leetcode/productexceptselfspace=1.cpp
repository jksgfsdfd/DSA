class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int size=nums.size();
        vector<int> right(size);
        
        right[size-1]=1;
        for(int i=1;i<=size-1;i++){
            right[size-1-i]=right[size-1-i+1]*nums[size-1-i+1];
        }
        
        int leftpr=1;
        for(int i=0;i<=size-1;i++){
            right[i]=leftpr*right[i];
            leftpr=leftpr*nums[i];
        }
        
        return right;
    }
};
