class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        if(N==0){
            return 0;
        }
        int min_cost_0;
        int min_cost_1;
        {
            int prev_cost = 0;
            int prev_prev_cost = 0;
            if(N==1){
                return cost[0];
            }
            if(N==2){
                return min(cost[0],cost[1]);
            }
            
            if(N==3){
                return min(cost[1],cost[0]+cost[2]);
            }

            int curr_cost;
            for(int i=N-3;i>=1;i--){
                curr_cost = min(prev_cost+cost[i+1],prev_prev_cost+cost[i+2]);
                prev_prev_cost=prev_cost;
                prev_cost = curr_cost;
            }
            
            int min_cost_of_0= min(curr_cost+cost[1],prev_prev_cost+cost[2]);
            return min(curr_cost+cost[1],min_cost_of_0+cost[0]);

            
        }
        
       
    }
};
