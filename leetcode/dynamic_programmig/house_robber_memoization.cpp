class Solution {
public:
    int sum(vector<int>&nums , int end ,vector<int>& dp){
    
        if(end==0){
            return nums[0];
        }    
        if(end==-1){
            return 0;
        }
        if(dp[end]!=-1){
            return dp[end];
        }
        int sum1 = sum(nums,end-1,dp);
        int sum2 = sum(nums,end-2,dp)+nums[end];
        
        return dp[end]=max(sum1,sum2);
    }
    
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,-1);
        
        return sum(nums,N-1,dp);
    }
};
