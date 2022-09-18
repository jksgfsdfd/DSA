class KthLargest {
    int size;
    priority_queue<int,vector<int>,greater<int>>heap;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size() && i<k;i++){
            heap.push(nums[i]);
        }
        if(k<nums.size()){
            for(int i=k;i<nums.size();i++){
                if(nums[i]>heap.top()){
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(heap.size()<size){
            heap.push(val);
            return heap.top();
        }
        if(val>heap.top()){
            heap.pop();
            heap.push(val);
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
