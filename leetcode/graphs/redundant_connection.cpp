class Solution {
public:
    bool hasPath(vector<vector<int>>& graph,int x,int y){
        unordered_set<int> seen;
        queue<int> qu;
        for(int ele : graph[x]){
            qu.push(ele);
            seen.insert(ele);
        }
        while(!qu.empty()){
            int ele = qu.front();
            if(ele==y){
                return true;
            }
            qu.pop();
            for(int num : graph[ele]){
                if(seen.find(num)==seen.end()){
                    seen.insert(num);
                    qu.push(num);
                }
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //when inserting each edge check whether already there is a path
        int size = edges.size();
        vector<vector<int>> graph(size+1);
        for(auto edge : edges){
            int x = edge[0];
            int y = edge[1];
            if(hasPath(graph,x,y)){
                return edge;
            }else{
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        return {};
    }
};
