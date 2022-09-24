class Solution {
public:
    typedef pair<int,int> point;
    
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int time = 0;
    bool reached = false;
    
    priority_queue<pair<int,point>,vector<pair<int,point>>,greater<pair<int,point>>> to_visit;
    
    bool valid(int x,int y,int N){
        if(x<N and x>=0 and y<N and y>=0){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>& grid,point ele,vector<vector<bool>>& visited,int& N){
        if(ele.first==N-1 and ele.second==N-1){
            reached=true;
            return;
        }
        int x;
        int y;
        for(auto dir : directions){
            if(reached==true){
                return;
            }
            x = ele.first + dir.first;
            y = ele.second + dir.second;
            if(valid(x,y,N) and visited[x][y]==false){
                if(grid[x][y]<=time){
                    visited[x][y]=true;
                    dfs(grid,{x,y},visited,N);
                }else{
                    to_visit.push({grid[x][y],{x,y}});
                }
            }
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        point start = {0,0};
        
        int N = grid.size();
        
        vector<vector<bool>> visited(N,vector<bool>(N));
        
        visited[0][0]=true;
        to_visit.push({grid[0][0],{0,0}});
        //take min in the heap and add points reachable to the heap
        while(!to_visit.empty()){
            auto [newtime , new_point] = to_visit.top();
            to_visit.pop();
            time = newtime;
            dfs(grid,new_point,visited,N);
            if(reached==true){
                return time;
            }
        }
        
        
        return time;
        //check if neighbour of new_point is endpoint if yes stop 
        
    }
};
