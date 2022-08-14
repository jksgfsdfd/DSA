class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        vector <int> arr(nums);
        sort(nums.begin(),nums.end());
        int sum;
        while(left<right){
            sum=nums[left]+nums[right];
            if(sum==target){
                int j=-1;
                int k=-1;
                
                for(int i=0;i<nums.size();i++){
                    if(arr[i]==nums[left] && j==-1){
                      j=i;  
                    }
                    if(arr[i]==nums[right] && k==-1){
                        k=i;
                    }
                    
                    
                    if(j!=-1 && k!=-1){
                        if(j==k){
                            k=-1;
                        }else{
                            break;
                        }
                        
                    }
                }
                vector <int> indices={j,k};
                return indices;
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return {};
        
    }
};
