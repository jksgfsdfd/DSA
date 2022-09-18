class Solution {
public:
    typedef pair<int,int> point_pair;
    
    bool haspath(vector<vector<int>>& graph,int p1,int p2){
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(p1);
        visited.insert(p1);
        while(!qu.empty()){
            int ele = qu.front();
            qu.pop();
            if(ele==p2){
                return true;
            }
            for(int point : graph[ele]){
                if(visited.find(point)==visited.end()){
                    qu.push(point);
                    visited.insert(point);
                }
            }
        }
        return false;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        //find all connection path costs 
        //start including from least...if already connected those two them avoid
        int size = points.size();
        vector<vector<int>> graph(size);
        vector<pair<int,point_pair>> edges;
        for(int i=0;i<size;i++){
            int x = points[i][0];
            int y = points[i][1];
            for(int j=i+1;j<size;j++){
                int other_x = points[j][0];
                int other_y = points[j][1];
                int dist = abs(x-other_x) + abs(y-other_y);
                edges.push_back({dist,{i,j}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int count = 0;
        int sum=0;
        for(auto edge : edges){
            auto [ point1 , point2 ] = edge.second;
            if(haspath(graph,point1,point2)){
                continue;
            }else{
                sum+=edge.first;
                graph[point1].push_back(point2);
                graph[point2].push_back(point1);
                count++;
                if(count==size-1){
                    return sum;
                }
            }
        }
        
        return sum;
    }
};
