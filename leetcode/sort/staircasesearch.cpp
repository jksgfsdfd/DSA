class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        if(rows<2){      
            return binarysearch(matrix[0],0,matrix[0].size()-1,target);
        }
        int rowindex=-1;
        for(int i=1;i<rows;i++){
            if(target<matrix[i][0]){
                rowindex=i-1;
                break;
            }else if(target==matrix[i][0]){
                return true;
            }
        }
        if(rowindex==-1){
            int lastsize=matrix[rows-1].size();
            if(target<=matrix[rows-1][lastsize-1]){
                rowindex=rows-1;
            }else{
                return false;
            }
        }
        
        int start=0;
        int end=matrix[rowindex].size()-1;
        return binarysearch(matrix[rowindex],start,end,target);
    }
    
    bool binarysearch(vector<int>arr,int start ,int end,int target){
        if(start>=end){
            if(arr[start]==target){
                return true;
            }
            return false;
        }
        int mid=(start+end)/2;
        
        if(target==arr[mid]){
            return true;
        }else if(target<arr[mid]){
            return binarysearch(arr,start,mid-1,target);
        }else{
            return binarysearch(arr,mid+1,end,target);
        }
        
    }
};
