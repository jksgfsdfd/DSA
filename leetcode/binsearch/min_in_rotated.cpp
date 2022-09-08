class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start_index=0;
        int size=nums.size();
        int end_index=size-1;
        int mid;
        int rot_index=-1;
        if(nums[start_index]<=nums[end_index]){
            return nums[start_index];
        }
        
        while(start_index+1<end_index){
            mid=(start_index+end_index)/2;
            if(nums[mid]>nums[end_index]){
                start_index=mid;
            }else{
                end_index=mid;
            }
        }
        rot_index=start_index;
        return nums[rot_index+1];
    }
};
