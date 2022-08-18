class Solution {
public:
    int trap(vector<int>& a) {
        int index=0;
        int lindex,lmaxindex;
        int rindex,rmaxindex;
        int size=a.size();
        int max=0;
        int ltrap=0;
        int rtrap=0;
        for(int i=0;i<size;i++){
            a[i]>max ? max=a[i] , index=i : max=max;
        }
        lindex=index-1;
        int lmax=0;
        while(lindex>-1){
            lmax=0;
            for(int i=0;i<=lindex;i++){
                a[i]>=lmax ? lmax=a[i] , lmaxindex=i : lmax=lmax;
            }
            int area=(lindex+1-lmaxindex-1)*lmax;
            int sum=0;
            for(int i=lmaxindex+1;i<=lindex;i++){
                sum+=a[i];
            }
            ltrap=ltrap+area-sum;
            lindex=lmaxindex-1;
        }
        
        rindex=index+1;
        int rmax=0;
        while(rindex<size){
            rmax=0;
            for(int i=rindex;i<size;i++){
                a[i]>=rmax ? rmax=a[i] , rmaxindex=i : rmax=rmax;
            }
            int area=(rmaxindex-(rindex-1)-1)*rmax;
            int sum=0;
            for(int i=rindex;i<rmaxindex;i++){
                sum+=a[i];
            }
            rtrap=rtrap+area-sum;
            rindex=rmaxindex+1;
        }
        return(rtrap+ltrap);
    }
    
};
