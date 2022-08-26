class Solution {
public:
    
    bool isvalid(vector<string>& matrix,int row_index,int col_index,int size){
        int i=row_index-1;
        int j=col_index;
        //coloumn check
        for(;i>=0;i--){
            if(matrix[i][j]=='Q'){
                return false;
            }
        }
        
        //right upper diagonal check
        i=row_index-1;
        j=col_index+1;
        while(i>=0 and j<size){
            if(matrix[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        
        //left upper diagonal check
        i=row_index-1;
        j=col_index-1;
        while(i>=0 and j>=0){
            if(matrix[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        return true;
    }
    
    void nqueens(vector<vector<string>>& answer,vector<string>& matrix,int row_index,int size){
        
        if(row_index==size-1){
            for(int k=0;k<size;k++){
                if(isvalid(matrix,row_index,k,size)){
                    matrix[row_index][k]='Q';
                    answer.push_back(matrix);
                    matrix[row_index][k]='.';
                }
            }
            return;
        }
        
        
        for(int k=0;k<size;k++){
            if(isvalid(matrix,row_index,k,size)){
                matrix[row_index][k]='Q';
                nqueens(answer,matrix,row_index+1,size);
                matrix[row_index][k]='.';
                }
            }
        
        return ;
        }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> answer;
        
        vector<string> dot_matrix;
        string dots;
        for(int i=0;i<n;i++){
            dots+=".";
        }
        for(int i=0;i<n;i++){
            dot_matrix.push_back(dots);
        }
        for(string s : dot_matrix){
            cout<<s<< endl;
        }
        
        vector<string> matrix(dot_matrix);
        
        int start_pos=0;
        nqueens(answer,matrix,0,n);
        
        
        return answer;
    }
};
