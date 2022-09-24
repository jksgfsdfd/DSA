class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        int answer = nums[N-1];
        vector<pair<int,int>>dp(N);
        dp[N-1]={nums[N-1],nums[N-1]};
        for(int i=N-2;i>=0;i--){
            if(nums[i]>=0){
                dp[i].first=max(nums[i],nums[i]*dp[i+1].first);
                dp[i].second=min(nums[i],nums[i]*dp[i+1].second);
                if(dp[i].first>answer){
                    answer=dp[i].first;
                }
            }
            if(nums[i]<0){
                dp[i].first=max(nums[i],nums[i]*dp[i+1].second);
                dp[i].second=min(nums[i],nums[i]*dp[i+1].first);
                if(dp[i].first>answer){
                    answer=dp[i].first;
                }
            }
        }
        return answer;
    }
};
