class Solution {
public:
    int rob(vector<int>& nums) {
        
        int N = nums.size();
        
        if(N==0){
            return 0;
        }
        
        if(N==1){
            return nums[0];
        }
        
        if(N==2){
            return max(nums[0],nums[1]);
        }
        
        int house1=nums[0];
        int house2=nums[1];
        
        for(int i=1;i<=(N/2)-1;i++){
            int old_house1 = house1;
            house1=max(house2,house1+nums[2*i]);
            house2=(max(old_house1,house2) + nums[2*i+1]);
        }
        
        if(N%2==1){
            house1=house1+nums[N-1];
        }
        
        return max(house1,house2);
    }
};
