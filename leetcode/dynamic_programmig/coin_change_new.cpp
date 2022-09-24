class Solution {
public:
    int dp[10001] = {[0 ... 10000] = -1};
    
    int findway(vector<int>& coins,int amount){
        if(amount<0){
            return INT_MAX;
        }
        if(amount==0){
            return 0;
        }
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int count=0;
        int mini=INT_MAX;
        for(auto ele : coins){
            if(ele<=amount){
                count=findway(coins,amount-ele);
                if(count!=INT_MAX){
                    count++;
                }
                mini=min(count,mini);
            }
        }
        dp[amount]=mini;
        return mini;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = findway(coins,amount); 
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
