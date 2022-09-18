class Solution {
public:
    bool findword(vector<vector<char>>& board,string word,int word_index,int board_i,int board_j){
        if(word_index == word.length()){
            return true;
        }
        
        if(board_i < 0 || board_j < 0){
            return false;
        }
        
        if(board_i >= board.size() || board_j >=board[0].size()){
            return false;
        }
        
        //if(board_i and board_j is already in the checked set return false)
        
        if(board[board_i][board_j]!=word[word_index]){
            return false;
        }
        
        
        board[board_i][board_j]='1';
        
        bool answer;
                    answer = findword(board,word,word_index+1,board_i,board_j+1);
                    if(answer){
                      return true;
                    }
                    answer = findword(board,word,word_index+1,board_i+1,board_j);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index+1,board_i-1,board_j);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index+1,board_i,board_j-1);
                    if(answer){
                        return true;
                    }
        
        board[board_i][board_j] = word[word_index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int coloums = board[0].size();
        bool answer;
        //find first matching letter 
        for(int i=0;i<rows;i++){
            for(int j=0;j<coloums;j++){
                if(board[i][j]==word[0]){
                    int word_index=1;
                    board[i][j]='1';
                    answer = findword(board,word,word_index,i,j+1);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index,i+1,j);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index,i-1,j);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index,i,j-1);
                    if(answer){
                        return true;
                    }
                    board[i][j]=word[0];
                }
            }
        }
        return false;
    }
};
