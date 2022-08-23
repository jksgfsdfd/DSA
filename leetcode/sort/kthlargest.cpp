class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        int pos=nums.size()-k;
        int start=0;
        int end=nums.size()-1;
        kthlargest(nums,pos,start,end,ans);
        return ans;
    }
    
    void kthlargest(vector<int>&nums,int pos,int start,int end,int &ans){
        if(start>=end){
            ans=nums[start];
            return;
        }
        float sum=0;
        float size=end-start+1;
        for(int i=start;i<=end;i++){
            sum+=nums[i];
        }
        float avg=sum/size;
        int i=start-1;
        int j=start;
        int temp;
        for(;j<=end;j++){
            if(nums[j]<=avg){
                i++;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
        if(i==end){
            ans=nums[i];
            return ;
        }
        if(i<pos){
            kthlargest(nums,pos,i+1,end,ans);
        }else if(i>pos){
            kthlargest(nums,pos,start,i,ans);
        }else{
            int max=INT_MIN;
            for(int m=start;m<=pos;m++){
                if(nums[m]>max){
                    max=nums[m];
                }
            }
            ans=max;
            return;
        }
    }
};
