class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1){
            vector<vector<int>> ans;
            ans.push_back(nums);
            return ans;
        }
        int add_num=nums.back();
        nums.pop_back();
        vector<vector<int>> prev_list=permute(nums);
        vector<vector<int>> ans;
        vector<int>ans_list;
        for(vector<int> arr:prev_list){
            int size=arr.size();
            for(int i=0;i<=size;i++){
                ans_list.clear();
                for(int j=0;j<size;j++){
                    if(j==i){
                        ans_list.push_back(add_num);
                        ans_list.push_back(arr[j]);
                    }else{
                        ans_list.push_back(arr[j]);
                    }
                }
                if(i==size){
                    ans_list.push_back(add_num);
                }
                ans.push_back(ans_list);
            }
        }
        return ans;
    }
};
