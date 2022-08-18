class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int smallindex=-1;
        int smallest=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                while(i<n){
                    if(nums[i]<smallest){
                        smallest=nums[i];
                    }
                    i++;
                }
            }
        }
        
        int biggest=INT_MIN;
        int bigindex=-1;
        for(int i=n-1;i>=1;i--){
            if(nums[i]<nums[i-1]){
                while(i>=0){
                    if(nums[i]>biggest){
                        biggest=nums[i];
                        
                    }
                    i--;
                }
            }
        }
        
        if(smallest==INT_MAX){
            return 0;
        }
        
        for(smallindex=0;nums[smallindex]<=smallest;smallindex++);
        for(bigindex=n-1;nums[bigindex]>=biggest;bigindex--);
        
        
        return (bigindex-smallindex+1);
    }
};
