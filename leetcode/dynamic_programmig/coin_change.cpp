class Solution {
public:
    unordered_map<int,int> dp;

    
    int minsum(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        
        if(dp.count(amount)){
            return dp[amount];
        }
        
        int min=-1;
        for(int coin : coins){
            int temp = minsum(coins,amount-coin);
            if(temp==-1){
                continue;
            }
            if(min==-1){
                min=temp;
            }
            if(temp<min){
                min=temp;
            }
        }
        
        
        
        if(min==-1){
            return dp[amount]=min;
        }
        
        return dp[amount]=min+1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
       
        return minsum(coins,amount);
        
        
    }
};
