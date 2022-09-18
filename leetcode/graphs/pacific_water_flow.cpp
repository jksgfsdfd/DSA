class Solution {
public:
    vector<pair<int,int>> pacific;
    vector<pair<int,int>> atlantic;
    vector<vector<int>> common;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool valid(int x,int y,int H,int W){
        if(x<H and x>=0 and y<W and y>=0)
            return true;
        return false;
    }
    
    
    
    void dfs(vector<vector<int>>& heights,int x,int y,const int &H,const int &W,vector<vector<bool>>& visited,bool& ocean){
        
        
        
        for(auto dir : directions){
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            
            if(valid(new_x,new_y,H,W) && heights[x][y]<=heights[new_x][new_y] && visited[new_x][new_y]==false){
                if(ocean==0){
                    pacific.push_back({new_x,new_y});
                }else{
                    atlantic.push_back({new_x,new_y});
                }
                visited[new_x][new_y]=true;
                dfs(heights,new_x,new_y,H,W,visited,ocean);
            }
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int H = heights.size();
        if(H==0){
            return {{}};
        }
        int W = heights[0].size();
        bool ocean = 0;
       vector<vector<bool>> visited (H,vector<bool>(W));
        for(int j=0;j<W;j++){
            if(visited[0][j]==false){
                visited[0][j]=true;
                pacific.push_back({0,j});
                dfs(heights,0,j,H,W,visited,ocean);
            }
        }
        for(int i=1;i<H;i++){
            if(visited[i][0]==false){
                visited[i][0]=true;
                pacific.push_back({i,0});
                dfs(heights,i,0,H,W,visited,ocean);
            }
        }
        
        ocean=1;
        visited.assign(H,vector<bool>(W));
        
        for(int j=0;j<W;j++){
            if(visited[H-1][j]==false){
                visited[H-1][j]=true;
                atlantic.push_back({H-1,j});
                dfs(heights,H-1,j,H,W,visited,ocean);
            }
        }
        for(int i=0;i<H-1;i++){
            if(visited[i][W-1]==false){
                visited[i][W-1]=true;
                atlantic.push_back({i,W-1});
                dfs(heights,i,W-1,H,W,visited,ocean);
            }
        }
        
        
        
        for(auto elepac : pacific){
            for(auto eleatl : atlantic){
                if(elepac==eleatl){
                    vector<int> ele;
                    ele.push_back(elepac.first);
                    ele.push_back(elepac.second);
                    common.push_back(ele);
                    break;
                }
            }
        }
        
       
        return common;
    }
};
