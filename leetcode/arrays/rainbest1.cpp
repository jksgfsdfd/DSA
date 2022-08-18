class Solution {
public:
    int trap(vector<int>& height) {
        
        //array of max element to left
        
        vector<int>left(height);
        for(int i=1;i<height.size();i++){
            if(left[i]<left[i-1]){
                left[i]=left[i-1];
            }
        }
        
        //array of max element to right
        
        vector<int>right(height);
        for(int i=height.size()-2;i>=0;i--){
            if(right[i]<right[i+1]){
                right[i]=right[i+1];
            }
        }
        
        //trapped water at an index = min(left,right) - height[index]
        int trap=0;
        for(int i=0;i<height.size();i++){
            trap+=((left[i]<right[i] ? left[i] : right[i])-height[i]);
        }
        
        return trap;
        
    }
};
