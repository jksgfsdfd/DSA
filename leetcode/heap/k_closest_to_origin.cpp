class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> heap;
        int dist;
        for(auto ele : points){
            dist=(ele[0]*ele[0])+(ele[1]*ele[1]);
            if(heap.size()<k){
                heap.push({dist,ele});
            }else{
                if(dist<heap.top().first){
                    heap.pop();
                    heap.push({dist,ele});
                }
            }
        }
        vector<vector<int>> answer;
        while(heap.size()){
            answer.push_back(heap.top().second);
            heap.pop();
        }
        return answer;
        
    }
};
