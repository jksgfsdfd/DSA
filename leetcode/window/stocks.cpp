class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int end=prices.size()-1;
        int right_max[end+1];
        right_max[end]=0;
        for(int i=end-1;i>=0;i--){
            if(prices[i+1]>right_max[i+1]){
                right_max[i]=prices[i+1];
            }else{
                right_max[i]=right_max[i+1];
            }
        }
        int max=INT_MIN;
        int profit=0;
        for(int i=0;i<=end;i++){
            profit=right_max[i]-prices[i];
            if(profit>max){
                max=profit;
            }
        }
        if(max<=0){
            return 0;
        }
        return max;
    }
};
