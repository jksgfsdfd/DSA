class Solution {
public:
    
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool valid(int x,int y,const int & H , const int & W){
        if(x<H and x>=0 and y<W and y>=0){
            return true;
        }
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int H = grid.size();
        if(H==0){
            return 0;
        }
        
        int W = grid[0].size();
        
        vector<vector<bool>> visited (H,vector<bool>(W));
        vector<vector<int>> times (H,vector<int>(W,INT_MAX));
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(grid[i][j]==2){
                    if(visited[i][j]==false){
                        visited[i][j]=true;
                        queue<pair<pair<int,int>,int>> que;
                        que.push({{i,j},0});
                        while(!que.empty()){
                            int x = que.front().first.first;
                            int y = que.front().first.second;
                            int time=que.front().second;
                            que.pop();
                            
                            for(auto dir : directions){
                                int new_x = x + dir.first;
                                int new_y = y + dir.second;
                                if(valid(new_x,new_y,H,W) and grid[new_x][new_y]==1 ){
                                    if(visited[new_x][new_y]==false){
                                        visited[new_x][new_y]=true;
                                        times[new_x][new_y]=time+1;
                                        que.push({{new_x,new_y},time+1});
                                    }else{
                                        if(time+1<times[new_x][new_y]){
                                            times[new_x][new_y]=time+1;
                                            que.push({{new_x,new_y},time+1});
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        int maxtime=0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(grid[i][j]==1 and visited[i][j]==false){
                    return -1;
                }else if(grid[i][j]==1){
                    if(times[i][j]>maxtime){
                        maxtime=times[i][j];
                    }
                }
            }
        }
        
        return maxtime;
    }
};
