class Solution {
public:
    
    bool check(vector<int> position,int gap,int count){
        int end=position.size()-1;
        int placed=1;
        int prevpos=0;
        for(int i=1;i<=end;i++){
         if(position[i]-position[prevpos]>=gap){
             prevpos=i;
             placed++;
             if(placed>=count){
                 return true;
             }
         }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int size=position.size();
        sort(position.begin(),position.end());
        int start=0;
        int end=position[size-1]-position[0];
        int ans=-1;
        bool isvalid;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            isvalid= check(position,mid,m);
            if(isvalid){
                if(mid>ans){
                    ans=mid;
                }
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};
