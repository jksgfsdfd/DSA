class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int size=nums.size();
        vector<int> left(size);
        vector<int> right(size);
        left[0]=1;
        right[size-1]=1;
        for(int i=1;i<=size-1;i++){
            left[i]=left[i-1]*nums[i-1];
            right[size-1-i]=right[size-1-i+1]*nums[size-1-i+1];
        }
        
        vector <int> result(size);
        for(int i=0;i<=size-1;i++){
            result[i]=(left[i]*right[i]);
        }
        
        return result;
    }
};
