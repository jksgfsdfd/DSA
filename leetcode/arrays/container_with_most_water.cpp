class Solution {
public:
    int min(int a,int b){
        if(a<b){
            return a;
        }else{
            return b;
        }
    }
    
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max=INT_MIN;
        int area;
        while(left<=right){
            area=(right-left)*min(height[left],height[right]);
            if(area>max){
                max=area;
            }
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
            
        }
        return max;
    }
};
