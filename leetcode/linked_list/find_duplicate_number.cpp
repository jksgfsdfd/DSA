class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        int right=size-1;
        int left=1;
        int count_right=0;
        int count_left=0;
        int count_ele=0;
        int mid=(left+right)/2;
        
        for(;;){
            count_right=0;
            count_left=0;
            count_ele=0;
            mid=(left+right)/2;
            for(int ele : nums){
                if(ele>=left and ele <=right){
                    if(ele>mid){
                        count_right++;
                    }else if(ele < mid){
                        count_left++;
                    }else{
                        count_ele++;
                        if(count_ele>1){
                            return mid;
                        }
                    }
                }
            }
            if(count_right>right-mid){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
};
