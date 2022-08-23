class Solution {
public:
    void quicksort(vector<int>&nums,int start,int end){
        if(start>=end){
            return;
        }
        int pivot=nums[end];
        int i=start-1;
        int j=start;
        int temp;
        for(;j<end;j++){
            if(nums[j]<pivot){
                i++;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
        nums[end]=nums[i+1];
        nums[i+1]=pivot;
        quicksort(nums,start,i);
        quicksort(nums,i+2,end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int end=nums.size()-1;
        quicksort(nums,0,end);
        return nums;
    }
    
    
};
