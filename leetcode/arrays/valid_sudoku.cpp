class Solution {
public:
    
    bool check_valid(vector<vector<char>> board,int check_i,int check_j){
        unordered_set<char> block_ele;
        for(int i=check_i;i<=check_i+2;i++){
            for(int j=check_j;j<=check_j+2;j++){
                //perform row check
                char c=board[i][j];
                if(c=='.'){
                    continue;
                }
                int temp=j+1;
                while(temp<9){
                    if(c==board[i][temp]){
                        return false;
                    }
                    temp++;
                }
                
                //perform coloumn check
                temp=i+1;
                while(temp<9){
                    if(c==board[temp][j]){
                        return false;
                    }
                    temp++;
                }
                //perform block check
                if(block_ele.find(c)!=block_ele.end()){
                    return false;
                }else{
                    block_ele.insert(c);
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int check_i=0;check_i<9;check_i+=3){
            for(int check_j=0;check_j<9;check_j+=3){
                bool valid=check_valid(board,check_i,check_j);
                if(!valid){
                    return false;
                }
            }
        }
        return true;
    }
};
