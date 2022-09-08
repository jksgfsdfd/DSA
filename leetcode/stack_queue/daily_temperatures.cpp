class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int>ans(size);
        int explo=size-1;
        ans[explo]=0;
        stack<int> index_stack;
        index_stack.push(explo);
        
        //we need not compare the lower indexed elements with elements that are smaller than current element but are indexed higher
        for(explo=size-2;explo>=0;explo--){
            while(!index_stack.empty() && temperatures[explo]>=temperatures[index_stack.top()]){
                index_stack.pop();
            }
            if(index_stack.empty()){
                ans[explo]=0;
            }else{
                ans[explo]=index_stack.top()-explo;
            }
            index_stack.push(explo);
        }
        return ans;
        
    }
};
