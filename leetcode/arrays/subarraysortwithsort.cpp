class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int lindex=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==sorted[i]){
                continue;
            }else{
                lindex=i;
                break;
            }
        }
        if(lindex==-1){
            return 0;
        }
        int rindex=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==sorted[i]){
                continue;
            }else{
                rindex=i;
                break;
            }
        }
        return (rindex-lindex+1);
    }
};
