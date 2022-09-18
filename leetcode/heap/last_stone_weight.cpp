class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(),stones.end());
        int max;
        int max_2;
        while(heap.size()>1){
            max=heap.top();
            heap.pop();
            max_2=heap.top();
            heap.pop();
            if(max==max_2){
                continue;
            }else{
                max=max-max_2;
                heap.push(max);
            }
        }
        if(heap.size()==0){
            return 0;
        }else{
            return heap.top();
        }
        
    }
};
