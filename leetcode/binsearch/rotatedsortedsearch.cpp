class Solution {
public:
    
    int binarysearch(vector<int>nums,int start,int end,int target){
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(target==nums[mid]){
                return mid;
            }else if(target<nums[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
    
    int findrotindex(vector<int>nums,int start,int end){
        if(start==end){
            return start;
        }
        int mid=(start+end)/2;
        if(start==mid){
            return start;
        }
        if(nums[start]>nums[mid]){
            return findrotindex(nums,start,mid);
        }else{
            return findrotindex(nums,mid,end);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int rotationindex=-1;
        int start=0;
        int ans=-1;
        int end=nums.size()-1;
        if(nums[0]<nums[end]){
            ans=binarysearch(nums,0,end,target);
        }else{
            rotationindex=findrotindex(nums,0,end);
            cout<<rotationindex<<endl;
            int ans1,ans2;
            ans1=binarysearch(nums,0,rotationindex,target);
            ans2=binarysearch(nums,rotationindex+1,end,target);
            if(ans1!=-1){
                ans=ans1;
            }else if(ans2!=-1){
                ans=ans2;
            }else{
                ans=-1;
            }
        }
        return ans;
    }
};
