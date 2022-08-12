class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> complis;
        for(int i=0;i<nums.size();i++){
            int compli=target-nums[i];
            if(complis.count(compli)){
                vector<int> indices;
                indices.push_back(i);
                indices.push_back(complis[compli]);
                return indices;
            }else{
                complis[nums[i]]=i;
            }
        }
        vector<int> indices;
        return indices;
    }
};
