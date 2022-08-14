class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen=0;
        unordered_set<int> set;
        for(int x: nums){
            set.insert(x);
        }
        int num,right,left;
        int rcount;
        int lcount;
        int count;
        while(set.size()>0){
            num = *set.begin();
            set.erase(num);
            right=num+1;
            left=num-1;
            rcount=lcount=0;
            while(set.find(right)!=set.end()){
                rcount++;
                set.erase(right);
                right=right+1;
            }
            while(set.find(left)!=set.end()){
                lcount++;
                set.erase(left);
                left=left-1;
            }
            count=lcount+rcount+1;
            if(count>maxlen){
                maxlen=count;
            }
        }
        return maxlen;
    }
};
