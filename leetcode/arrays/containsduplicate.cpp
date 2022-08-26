class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int x:nums){
            if(set.find(x)!=set.end()){
                return true;
            }else{
                set.insert(x);
            }
        }
        return false;
    }
    
};
