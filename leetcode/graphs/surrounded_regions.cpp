class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool valid(int x,int y,const int &  H,const int & W){
        if(x<H and x>=0 and y<W and y>=0){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& board,int x,int y,const int & H,const int & W,vector<vector<bool>>& visited,vector<vector<bool>>& makex){
        
        for(auto dir: directions){
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            
            if(valid(new_x,new_y,H,W) and board[new_x][new_y]=='O' and visited[new_x][new_y]==false ){
                visited[new_x][new_y]=true;
                makex[new_x][new_y]=false;
                dfs(board,new_x,new_y,H,W,visited,makex);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int H = board.size();
        if(H==0){
            return;
        }
        int W = board[0].size();
        vector<vector<bool>> makex(H,vector<bool>(W,true));
        vector<vector<bool>> visited(H,vector<bool>(W));
        for(int j=0;j<W;j++){
            if(board[0][j]=='O'){
                if(visited[0][j]==false){
                    visited[0][j]=true;
                    makex[0][j]=false;
                    dfs(board,0,j,H,W,visited,makex);
                }
            }
        }
        for(int j=0;j<W;j++){
            if(board[H-1][j]=='O'){
                if(visited[H-1][j]==false){
                    visited[H-1][j]=true;
                    makex[H-1][j]=false;
                    dfs(board,H-1,j,H,W,visited,makex);
                }
            }
        }
        for(int i=1;i<H-1;i++){
            if(board[i][0]=='O'){
                if(visited[i][0]==false){
                    visited[i][0]=true;
                    makex[i][0]=false;
                    dfs(board,i,0,H,W,visited,makex);
                }
            }
        }
        for(int i=1;i<H-1;i++){
            if(board[i][W-1]=='O'){
                if(visited[i][W-1]==false){
                    visited[i][W-1]=true;
                    makex[i][W-1]=false;
                    dfs(board,i,W-1,H,W,visited,makex);
                }
            }
        }
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(makex[i][j]==true){
                    board[i][j]='X';
                }
            }
        }
    }
};
