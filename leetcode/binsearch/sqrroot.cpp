class Solution {
public:
    int mySqrt(int x) {
        if(x<1){
            return 0;
        }
        int start=1;
        int end=pow(2,16);
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(pow(mid,2)<=x and x<pow(mid+1,2)){
                return mid;
            }else if(x<pow(mid,2)){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return 0;
    }
};
