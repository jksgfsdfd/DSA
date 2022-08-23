class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int end=nums.size()-1;
        mergeSort(nums,0,end);
        return nums;
    }
    
    void mergeSort(vector<int> &arr,int s,int e){
        //base case
        if(s>=e){
            return;
        }
        
        int left=s;
        int mid=(s+e)/2;
        int right=mid+1;
        mergeSort(arr,left,mid);
        mergeSort(arr,right,e);
        merge(arr,s,e);
        return;
    }
    
    void merge(vector<int>&arr,int s,int e){
        int left=s;
        int mid=(s+e)/2;
        int right=mid+1;
        vector<int>temp;
        while(left<=mid && right<=e){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        //copy whichever is remaining
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        
        while(right<=e){
            temp.push_back(arr[right++]);
        }
        
        int k=0;
        for(int i=s;i<=e;i++){
            arr[i]=temp[k++];
        }
        return;
    }
};
