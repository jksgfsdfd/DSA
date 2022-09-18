class Solution {
public:
    void subs(vector<int>& nums,int index,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back({});
            return;
        }
        subs(nums,index+1,ans);
        int size=ans.size();
        for(int i=0;i<size;i++){
            vector<int> temp = ans[i];
            temp.push_back(nums[index]);
            ans.push_back(temp);
        }
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<vector<int>> answer;
        subs(nums,index,answer);
        return answer;
    }
};
