class Solution {
public:
    pair<int,bool> profit(vector<int>& prices , int day,vector<pair<int,bool>>& dp){
        if(day==0){
            return {0,false};
        }
        if(day==1){
            if(prices[1]>prices[0]){
                return {prices[1]-prices[0],true};
            }else{
                return {0,false};
            }
        }
        
        if(dp[day].first!=-1){
            return dp[day];
        }
        
        bool sold;
        int curr_max=0;
        auto [ prev_max , sold_at_prev] = profit(prices,day-1,dp);
        auto [ prev_prev_max , sold_at_prev_prev] = profit(prices,day-2,dp);
        //int prev_prev_max = profit(prices,day-2);
        //sold on last day
        
        if(sold_at_prev){
            if(prices[day]>prices[day-1]){
                curr_max = prev_max + prices[day] - prices[day-1];
                sold=true;
            }else{
                curr_max=prev_max;
                sold=false;
            }
        }else{
            if(sold_at_prev_prev){
                //2 possibility either drop the previous or continue with previous
                int path1_max=0;
                int path2_max=0;
                bool sold1,sold2;     
                if(prices[day]>prices[day-2]){
                    path1_max = prev_prev_max + prices[day] - prices[day-2];
                    sold1=true;
                }else{
                    path1_max=prev_max;
                    sold1=false;
                }
                if(prices[day]>prices[day-1]){
                    auto [prev_prev_prev_max , temp] = profit(prices,day-3,dp); 
                    path2_max = prices[day]-prices[day-1] + prev_prev_prev_max;
                    sold2=true;
                }
                if(path2_max>path1_max){
                    curr_max=path2_max;
                    sold=sold2;
                }else{
                    curr_max=path1_max;
                    sold=sold1;
                }
                
            }else{
                if(prices[day]>prices[day-1]){
                    curr_max = prev_max + prices[day] - prices[day-1];
                    sold=true;
                }else{
                    curr_max=prev_max;
                    sold=false;
                }
            }
        }
        return dp[day]={curr_max,sold};
    }
    
    int maxProfit(vector<int>& prices) {
        
        int N = prices.size();
        vector<pair<int,bool>> dp(N,{-1,false});
        if(N<=1){
            return 0;
        }
        auto [ans,sold] = profit(prices,N-1,dp);
        for(int i=0;i<dp.size();i++){
            auto ele = dp[i];
            cout<<prices[i]<<" "<<ele.first<<" "<<ele.second<<endl;
        }
        return ans;
    }
};
