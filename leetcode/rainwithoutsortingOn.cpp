class Solution {
public:
    int trap(vector<int>& height) {
        
        //array of index of max element to left
        
        if(height.size()<2){
            return 0;
        }
        
        int size=height.size();
        
        vector<int>left(height.size());
        left[0]=-1;
        for(int i=1;i<height.size();i++){
            if(i==1){
                left[i]=0;
            }else{
                if(height[i-1]>height[left[i-1]]){
                    left[i]=i-1;
                }else{
                    left[i]=left[i-1];
                }
            }
            
        }
        
        //array of max element to right
        
        vector<int>right(height.size());
        
        right[height.size()-1]=-1;
        for(int i=height.size()-2;i>=0;i--){
            if(i==height.size()-2){
                right[i]=height.size()-1;
            }else{
                if(height[i+1]>height[right[i+1]]){
                    right[i]=i+1;
                }else{
                    right[i]=right[i+1];
                }
            }
            
        }
        
        cout<<"the left indices are ";
        for(int x:left){
            cout<<x<<" ";
        }
        cout<<endl;
        
        cout<<"the right indices are ";
        for(int x:right){
            cout<<x<<" ";
        }
        cout<<endl;
        
        //trapped water at an index = min(left,right) - height[index]
        int ltrap=0;
        int index=(height[right[0]]>height[left[height.size()-1]] ? right[0] : left[size-1]);
        int lindex=left[index];
        while(lindex>=0){
            int area=height[lindex]*(index-lindex-1);
            int sum=0;
            for(int i=lindex+1;i<index;i++){
                sum+=height[i];
            }
            ltrap+=(area-sum);
            index=lindex;
            lindex=left[lindex];
        }
        
      cout<<ltrap<<endl;
        
        int rtrap=0;
        index=(height[right[0]]>height[left[height.size()-1]] ? right[0] : left[size-1]);
        int rindex=right[index];
        while(rindex>=0){
            int area=height[rindex]*(rindex-index-1);
            int sum=0;
            for(int i=index+1;i<rindex;i++){
                sum+=height[i];
            }
            rtrap+=(area-sum);
            index=rindex;
            rindex=right[rindex];
        }
        
        cout<<rtrap<<endl;
        
        return (rtrap+ltrap);
        
    }
};
