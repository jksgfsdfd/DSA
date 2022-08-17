class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int number;
        int size=0;
        for(int i=nums.size()-1;i>=0;i--){
            number=nums[i];
            size=ans.size();
            for(int j=0;j<size;j++){
                vector<int> x=ans[j];
                x.push_back(number);
                ans.push_back(x);
            }
        }
        return ans;
    }
};
