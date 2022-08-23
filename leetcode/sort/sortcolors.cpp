class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int zero=-1;
        int j=0;
        int end=nums.size()-1;
        int two=end+1;
        int temp;
        for(;j<=end;j++){
            if(nums[j]==0){
                zero++;
                temp=nums[zero];
                nums[zero]=nums[j];
                nums[j]=temp;
            }     
        }
        j=end;
        for(;j>=0 and j>zero;j--){
            if(nums[j]==2){
                two--;
                temp=nums[two];
                nums[two]=nums[j];
                nums[j]=temp;
            }     
        }
        return nums;
    }
    
    
};
