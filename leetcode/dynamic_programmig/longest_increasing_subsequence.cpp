class Solution {
public:
    
    
    int lis(vector<int>& nums,int index,int end,vector<int>& dp){
        if(index==end){
            return 1;
        }
        int this_max = 1;
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=index+1;i<=end;i++){
            int others_max = lis(nums,i,end,dp);
            if(nums[index]<nums[i]){
                others_max = others_max + 1;
            }else{
                others_max=1;
            }
            if(others_max>this_max){
                this_max=others_max;
            }
        }
        return dp[index]=this_max;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,-1);
        
        int max = lis(nums,0,N-1,dp);
        for(int a : dp){
            if(a>max){
                max=a;
            }
        }
        return max;
    }
};
