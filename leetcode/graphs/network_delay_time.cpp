class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto edge : times){
            int source = edge[0];
            int dest = edge[1];
            int weight = edge[2];
            graph[source].push_back({dest,weight});
        }
        
        for(auto edge : graph[k]){
            
            min_heap.push({edge.second,edge.first});
        }
        
        unordered_set<int>reached;
        reached.insert(k);
        int maxtime;
        int count=1;
        while(!min_heap.empty()){
            auto [ weight , vertex ] = min_heap.top();
            min_heap.pop();
            if(reached.find(vertex)==reached.end()){
                reached.insert(vertex);
                maxtime = weight;
                count++;
                if(count==n){
                    return weight;
                }
                for(auto new_vertex : graph[vertex]){
                    if(reached.find(new_vertex.first)==reached.end()){
                        min_heap.push({new_vertex.second+weight,new_vertex.first});
                    }
                }
            }
        }
        return -1;
        
    }
};
