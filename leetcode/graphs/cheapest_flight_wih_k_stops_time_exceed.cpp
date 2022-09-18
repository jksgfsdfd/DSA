class Solution {
public:
    int sum=0;
    unordered_map<int,pair<int,int>> visited;
    int minsum=INT_MAX;
    void dfs(unordered_map<int,unordered_map<int,int>>& graph,int src,int end,int stops){
        
        
        if(src==end){
            if(sum<minsum){
                minsum=sum;
            }
            return;
        }
        
        if(stops==0){
            return;
        }
        
        for(auto [dest,price] : graph[src]){
            if(visited.find(dest)==visited.end()){
                visited[dest].first=stops;
                
                sum+=price;
                visited[dest].second=sum;
                dfs(graph,dest,end,stops-1);
                sum-=price;
            }else if(stops>visited[dest].first or sum+price<visited[dest].second){
                sum+=price;
                
                dfs(graph,dest,end,stops-1);
                sum-=price;
            }else{
                continue;
                                
            }
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
        visited[src]={k+2,0};
        dfs(graph,src,dst,k+1);
        
        if(minsum==INT_MAX){
            return -1;
        }
        return minsum;
    }
    
    //list all routes with max k stops
    
};
