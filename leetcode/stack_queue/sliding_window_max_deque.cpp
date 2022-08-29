class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size=nums.size();
        deque<int> deq(k);
        vector<int> answer;
        deq.push_front(0);
        for(int i=0;i<=k-1;i++){
            if(nums[i]>=nums[deq.front()]){
                deq.clear();
                deq.push_front(i);
            }else{
                while(nums[i]>=nums[deq.back()]){
                    deq.pop_back();
                }
                deq.push_back(i);
            }
        }
        
        answer.push_back(nums[deq.front()]);
        for(int i=k;i<size;i++){
            if(deq.front()<=i-k){
                deq.pop_front();
            }
            if(deq.empty()){
                deq.push_front(i);
            }
            if(nums[i]>=nums[deq.front()]){
                deq.clear();
                deq.push_front(i);
            }else{
                while(nums[i]>=nums[deq.back()]){
                    deq.pop_back();
                }
                deq.push_back(i);
            }
            answer.push_back(nums[deq.front()]);
        }
        return answer;
    }
};
