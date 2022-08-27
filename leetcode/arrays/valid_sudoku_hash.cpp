class Solution {
public:
    
    bool check_valid_block(vector<vector<char>> board,int check_i,int check_j){
        unordered_set<char> block_ele;
        for(int i=check_i;i<=check_i+2;i++){
            for(int j=check_j;j<=check_j+2;j++){
               
                char c=board[i][j];
                if(c=='.'){
                    continue;
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
                bool valid=check_valid_block(board,check_i,check_j);
                if(!valid){
                    return false;
                }
            }
        }
        
        //perform row check
        for(int i=0;i<9;i++){
            unordered_set<char> row_ele;
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.'){
                    continue;
                }
                if(row_ele.find(c)!=row_ele.end()){
                    return false;
                }else{
                    row_ele.insert(c);
                }
            }
        }
        
        //perform coloumn check
        for(int i=0;i<9;i++){
            unordered_set<char> col_ele;
            for(int j=0;j<9;j++){
                char c=board[j][i];
                if(c=='.'){
                    continue;
                }
                if(col_ele.find(c)!=col_ele.end()){
                    return false;
                }else{
                    col_ele.insert(c);
                }
            }
        }
        return true;
    }
};
