class Solution {
public:
    
    bool solve_sudoku(vector<vector<char>>& board,int row_index,int col_index){
        for(char c='1';c<='9';c++){
            bool check_next=0;
            
            //perform row check
            for(int j=0;j<9;j++){
                if(board[row_index][j]==c){
                    check_next=1;
                    break;
                }
            }
            
            if(check_next==1){
                continue;
            }
            
            //perform col check
            for(int i=0;i<9;i++){
                if(board[i][col_index]==c){
                    check_next=1;
                    break;
                }
            }
            
            if(check_next==1){
                continue;
            }
            
            //perform block check
            int block_start_i=(row_index/3);
            int block_start_j=(col_index/3);
            for(int i=(block_start_i*3);i<=(block_start_i*3+2);i++){
                for(int j=(block_start_j*3);j<=(block_start_j*3+2);j++){
                    if(board[i][j]==c){
                        check_next=1;
                        break;
                    }
                }
                if(check_next==1){
                    break;
                }
            }
            
            if(check_next==1){
                continue;
            }
            
            board[row_index][col_index]=c;
            
            
            //finding the next positon to check
            int i=row_index;
            int j=col_index;
            while(i<9){
                if(j==8){
                    i++;
                }
                if(i==9){
                    return true;
                }
                j=(j+1)%9;
                if(board[i][j]=='.'){
                    break;
                }
            }
            
            
            bool success=solve_sudoku(board,i,j);
            if(success){
                return true;
            }
            board[row_index][col_index]='.';
            
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int row_index=0;
        int col_index=0;
        bool exit=0;
        for(;row_index<9;row_index++){
            for(col_index=0;col_index<9;col_index++){
                if(board[row_index][col_index]=='.'){
                    exit=1;
                    break;
                }
            }
            if(exit){
                break;
            }
        }
        bool success=solve_sudoku(board,row_index,col_index);
        
    }
};
