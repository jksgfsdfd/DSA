class Solution {
public:
    bool findword(vector<vector<char>>& board,string word,int word_index,int board_i,int board_j,unordered_map<int,unordered_set<int>>& used_pos){
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
        if(used_pos.find(board_i) != used_pos.end()){
            if(used_pos[board_i].find(board_j)!=used_pos[board_i].end()){
                return false;
            }
        }
        
        
        if(board[board_i][board_j]!=word[word_index]){
            return false;
        }
           
        used_pos[board_i].insert(board_j);
        
        bool answer;
                    answer = findword(board,word,word_index+1,board_i,board_j+1,used_pos);
                    if(answer){
                      return true;
                    }
                    answer = findword(board,word,word_index+1,board_i+1,board_j,used_pos);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index+1,board_i-1,board_j,used_pos);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index+1,board_i,board_j-1,used_pos);
                    if(answer){
                        return true;
                    }
        used_pos[board_i].erase(board_j);
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
                    unordered_map<int,unordered_set<int>> used_pos;
                    unordered_set<int> a;
                    a.insert(j);
                    used_pos[i] = a;
                    answer = findword(board,word,word_index,i,j+1,used_pos);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index,i+1,j,used_pos);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index,i-1,j,used_pos);
                    if(answer){
                        return true;
                    }
                    answer = findword(board,word,word_index,i,j-1,used_pos);
                    if(answer){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
