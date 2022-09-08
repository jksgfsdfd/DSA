class Solution {
public:
    bool find_compli(vector<int>numbers,int compli,int left,int& right){
        int start=left;
        int end=right;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(compli==numbers[mid]){
                right=mid;
                return true;
            }else if(compli<numbers[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        right=end;
        return false;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left=0;
        int compli=target-numbers[left];
        int right=numbers.size()-1;
        
        while(left<right){
            bool success=find_compli(numbers,compli,left+1,right);
            if(success){
                return {left+1,right+1};
            }
            left=left+1;
            //check for error
            compli=target-numbers[left];
        }
        return {left+1,right+1};
    }
};
