class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //find frequency of each element using map O[n]
        unordered_map<int,int> freq_map;
        for(int a:nums){
            if(freq_map.find(a)!=freq_map.end()){
                freq_map[a]++;
            }else{
                freq_map[a]=1;
            }
        }
        
        //find the biggest k elements using heap O(n+klogn)
        priority_queue<pair<int,int>> heap;
        for(auto it:freq_map){
            heap.push({it.second,it.first});
        }
        
        vector<int> answer;
        for(int i=1;i<=k;i++){
            int ele=heap.top().second;
            answer.push_back(ele);
            heap.pop();
        }
        
        return answer;
    }
};
