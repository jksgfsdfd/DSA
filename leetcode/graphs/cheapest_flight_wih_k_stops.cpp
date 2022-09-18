class Solution {
public:
    int sum=0;
    unordered_map<int,int> parent;
    unordered_map<int,int> child;
    int minsum=INT_MAX;
    
    void bfs(unordered_map<int,unordered_map<int,int>>& graph,int start,int end,int k){
        parent[start]=0;
        while(k>=0){
            child = parent;
            for(auto [ele , sum] : parent){
                for(auto [dst , price] : graph[ele]){
                    if(child.count(dst)==0){
                        child[dst]=price+sum;
                    }else if(sum+price<child[dst]){
                        child[dst]=sum+price;
                    }
                }
            }
            k--;
            parent=child;
        }
        if(child.count(end)==0){
            minsum=-1;
        }else{
            minsum=child[end];
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,unordered_map<int,int>> graph;
        for(auto edge : flights){
            int src = edge[0];
            int dest = edge[1];
            int price = edge[2];
            graph[src][dest]=price;
        }
        
        bfs(graph,src,dst,k);
        
        
        return minsum;
    }
    
    //list all routes with max k stops
    
};
