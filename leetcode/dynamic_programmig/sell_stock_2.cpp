class Solution {
public:
    int profit(vector<int>& prices,int day){
        if(day==0){
            return 0;
        }
        int curr_max = 0;
        int prev_max = profit(prices,day-1);
        if(prices[day]>prices[day-1]){
            curr_max = prev_max + prices[day]-prices[day-1];
        }else{
            curr_max = prev_max;
        }
        return curr_max;
    }
    
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(N<=1){
            return 0;
        }
        return profit(prices,N-1);
    }
};
