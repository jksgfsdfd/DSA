class Solution {
public:
    int arr[20][4001] = {[0 ... 19] = {[0 ... 4000] = 5000}};
    
    int findways(vector<int>& nums,int target,int index){
        
        if(index==0 and (target==nums[0] or target==-nums[0])){
            if(target==0){
                return 2;
            }
            return 1;
        }
        if(index==-1){
            return 0;
        }
        
        int new_target;
        if(target<0){
            new_target=2000+-1*target;
        }else{
            new_target=target;
        }
        if(arr[index][new_target]!=5000){
            return arr[index][new_target];
        }
        
        int count=0;
        count+=findways(nums,target+nums[index],index-1);
        count+=findways(nums,target-nums[index],index-1);
        return arr[index][new_target]=count;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        return findways(nums,target,N-1);
    }
};
