class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int highest=nums[0];
        for(int x:nums){
            if(x>highest){
                highest=x;
            }
        }
        if(highest<=0){
            return highest;
        }
        
        int sum=0;
        highest=0;
        int size=nums.size();  
        int i=0;
        while(i<size){
            if(nums[i]>=0){
                sum=sum+nums[i];
                if(sum>highest){
                    highest=sum;
                }
            }else{
                
                sum+=nums[i];
                if(sum<0){
                    sum=0;
                }
            }
            i++;
        }
        
        return highest;
        
    }
};
