class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find the row in which it target will be present if it is present
        int rows=matrix.size();
        int start=0;
        int end=rows-1;
        int mid;
        int row;
        //only condition to fail this rowwise check is if ele>matrix[end][0] and belongs to last row
        if(target>matrix[end][0]){
            row=rows-1;
            end=matrix[end].size()-1;
            start=0;
            while(start<=end){
                mid=(start+end)/2;
                if(target==matrix[row][mid]){
                    return true;
                }
                if(target>matrix[row][mid]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            return false;
        }
        
        start=0;
        end=rows-1;
        while(start<=end){
            mid=(start+end)/2;
            if(target==matrix[mid][0]){
                return true;
            }
            if(target>matrix[mid][0]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        row=end;
        if(row<0){
            return false;
        }
        start=0;
        end=matrix[row].size()-1;
        while(start<=end){
            mid=(start+end)/2;
            if(target==matrix[row][mid]){
                return true;
            }
            if(target>matrix[row][mid]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
};
