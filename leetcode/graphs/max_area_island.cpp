class Solution {
public:
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return 0;
        }
        int maxarea=0;
        int H = grid.size();
        int W = grid[0].size();
        
        auto valid = [&](int x,int y){
            return (x<H && x>=0 && y<W && y>=0);
        };
        vector<vector<bool>> visited(H,vector<bool>(W));
        vector<pair<int,int>> directions= {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(visited[i][j]==false && grid[i][j]==1){
                    int curr_area=0;
                    queue<pair<int,int>> island;
                    island.push({i,j});
                    visited[i][j]=true;
                    while(!island.empty()){
                        pair<int,int> ele=island.front();
                        curr_area++;
                        island.pop();
                        for(auto dir : directions){
                            int x = ele.first + dir.first;
                            int y = ele.second + dir.second;
                            if(valid(x,y) && grid[x][y]==1 && visited[x][y]==false){
                                island.push({x,y});
                                visited[x][y]=true;
                            }
                        }
                    }
                    if(curr_area>maxarea){
                        maxarea=curr_area;
                    }
                }
            }
        }
        return maxarea;
    }
};
