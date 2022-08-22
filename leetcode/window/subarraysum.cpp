class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int target=k;
        int sum=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(map.count(sum)){
                map[sum]++;
            }else{
                map[sum]=1;
            }
        }
        if(map.count(target)){
            count+=map[target];
        }
        sum=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            target=target+nums[i];
            map[sum]--;
            if(map.count(target)){
                count+=map[target];
            }
        }
        return count;
    }
};
