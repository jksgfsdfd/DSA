class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int dp[200][200] = {[0 ... 199] = {[0 ... 199] = -1}};
    
    //int count=1;
    
    bool valid(int x,int y,int H,int W){
        if(0<=x and x<H and 0<=y and y<W){
            return true;
        }
        return false;
    }
    
    int findInc(vector<vector<int>>& matrix,int x,int y,int &H,int &W){
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int curr_length=1;
        for(auto dir:directions){
            int new_x = x + dir[0];
            int new_y = y + dir[1];
            if(valid(new_x,new_y,H,W) and matrix[new_x][new_y]>matrix[x][y]){
                int prev_length=findInc(matrix,new_x,new_y,H,W);
                curr_length=max(prev_length+1,curr_length);
            }
            
        }
        dp[x][y]=curr_length;
        return curr_length;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int H = matrix.size();
        int W = matrix[0].size();
        int longest=1;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                int len=findInc(matrix,i,j,H,W);
                if(len>longest){
                    longest=len;
                }
            }
        }
        return longest;
    }
};
