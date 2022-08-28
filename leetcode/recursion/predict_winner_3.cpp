class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return recur(nums,0,nums.size()-1)>=0;
    }
    int recur(vector<int>& n,int l, int r){
        if(l==r) return n[l];
        int left = recur(n,l+1,r);
        int right = recur(n,l,r-1);
        return max(n[l]-left,n[r]-right);
    }
};
