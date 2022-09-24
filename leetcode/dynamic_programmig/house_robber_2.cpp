class Solution {
public:
    int sum(vector<int>&nums ,const int& start, int end ,vector<int>& dp){
    
        
            if(end==start){
                return nums[start];
            }    
            if(end==start-1){
                return 0;
            }
        
        
        if(dp[end]!=-1){
            return dp[end];
        }
        int sum1 = sum(nums,start,end-1,dp);
        int sum2 = sum(nums,start,end-2,dp)+nums[end];
        
        return dp[end]=max(sum1,sum2);
    }
    
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,-1);
        
        if(N==0){
            return 0;
        }
        
        
        if(N==1){
            return nums[0];
        }
        
        if(N==2){
            return max(nums[0],nums[1]);
        }
        
        int max1= sum(nums,0,N-2,dp);
        dp.assign(N,-1);
        int max2= sum(nums,1,N-1,dp);
        return max(max1,max2);
    }
};
