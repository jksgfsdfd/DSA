class Solution {
public:
    unordered_map<int,unordered_map<int,bool>>dp;
    bool canmake(vector<int>& nums,int target,int index){
        if(target==0){
            return true;
        }
        if(target<0){
            return false;
        }
        if(index>=nums.size()){
            return false;
        }
        if(dp.count(index)){
            if(dp[index].count(target)){
                return dp[index][target];
            }
        }
        bool possible;
        possible = canmake(nums,target-nums[index],index+1);
        if(possible==true){
            return dp[index][target]=true;
        }
        possible = canmake(nums,target,index+1);
        if(possible==true){
            return dp[index][target]=true;
        }
        return dp[index][target]=false;
    }
    
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int total=0;
        for(int i=0;i<N;i++){
            total+=nums[i];
        }
        if(total%2){
            return false;
        }
        return canmake(nums,total/2,0);
    }
};
