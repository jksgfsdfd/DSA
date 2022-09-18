class Solution {
public:   
    bool valid(int x,int y,int H ,int W){
        if(x<H && x>=0 && y<W && y>=0 ){
            return true;
        }
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return 0;
        }
        int H = grid.size();
        int W = grid[0].size();
        vector<vector<bool>> visited(H,vector<bool>(W));
        int answer = 0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    answer++;
                    //do bfs
                    queue<pair<int,int>> island;
                    island.push({i,j});
                    while(!island.empty()){
                        pair<int,int>ele = island.front();
                        int x=ele.first;
                        int y=ele.second;
                        island.pop();
                        if(valid(x+1,y,H,W) && grid[x+1][y]=='1' && visited[x+1][y]==false){
                            visited[x+1][y]=true;
                            island.push({x+1,y});
                        }
                        if(valid(x-1,y,H,W) && grid[x-1][y]=='1' && visited[x-1][y]==false){
                            visited[x-1][y]=true;
                            island.push({x-1,y});
                        }
                        if(valid(x,y+1,H,W) && grid[x][y+1]=='1' && visited[x][y+1]==false){
                            visited[x][y+1]=true;
                            island.push({x,y+1});
                        }
                        if(valid(x,y-1,H,W) && grid[x][y-1]=='1' && visited[x][y-1]==false){
                            visited[x][y-1]=true;
                            island.push({x,y-1});
                        }
                    }
                }
            }
        }
        return answer;
    }
};
