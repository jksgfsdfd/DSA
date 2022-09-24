class Solution {
public:
    
    int dp[302][302] = {[0 ... 301] = {[0 ... 301] = -1}}; 
    
    int max_endsbetween(vector<int>&nums,int left,int right){
        if(left==right){
            return nums[left] * nums[left-1] * nums[left+1];
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        
        int ans=0;
        for(int i=left;i<=right;i++){
            int left_part = 0;
            if(i!=left){
                left_part = max_endsbetween(nums,left,i-1);
            }
            int right_part=0;
            if(i!=right){
                right_part= max_endsbetween(nums,i+1,right);
            }
            int this_ele_contrib = nums[i] * nums[left-1] * nums[right+1];
            int total = left_part + right_part + this_ele_contrib;
            ans = max(ans,total);
        }
        dp[left][right]=ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int>new_nums(nums);
        new_nums.emplace(new_nums.begin(),1);
        new_nums.push_back(1);
       
        int N = new_nums.size();
        return max_endsbetween(new_nums,1,N-2);
    }
};
