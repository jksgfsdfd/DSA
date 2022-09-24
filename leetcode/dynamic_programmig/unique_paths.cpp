class Solution {
public:
    vector<pair<int,int>>directions = {{-1,0},{0,-1}};
    int arra[101][101]= {[0 ... 100]={[0 ... 100] = -1} };
    int uniquePaths(int m, int n) {
        if(m==1 and n==1){
            return 1;
        }
        if(arra[m][n]!=-1){
            return arra[m][n];
        }
        int paths = 0;
        for(auto dir : directions){
            int new_x = m + dir.first;
            int new_y = n + dir.second;
            if(new_x>=1 and new_y>=1){
                paths += uniquePaths(new_x,new_y);
            }
        }
        return arra[m][n]=paths;
    }
};
