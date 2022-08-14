class Solution {
public:
    int longestMountain(vector<int>& a) {
        int len=0;
        int maxlen=0;
        int mountain=0;
        int size=a.size();
        int i=0;
        while(i<size){
            if(i==size-1){
                if(mountain==2){
                    len++;
                    if(len>maxlen){
                        maxlen=len;
                        return maxlen;
                    }
                }else{
                    return maxlen;
                }
            }
            if(mountain==0){
                while(i<size-1){
                    if(a[i]<a[i+1]){
                        mountain=1;
                        break;
                    }
                    i++;
                }
                len=1;
            }else if(mountain==1){
                if(a[i]==a[i+1]){
                    mountain=0;
                }else if(a[i]>a[i+1]){
                    len++;
                    mountain=2;
                }else{
                    len++;
                }
            }else if(mountain==2){
                len++;
                if(a[i]==a[i+1]){
                    if(len>maxlen){
                        maxlen=len;
                    }
                    mountain=0;
                    len=0;
                }else if(a[i]<a[i+1]){
                    if(len>maxlen){
                        maxlen=len;
                    }
                    mountain=1;
                    len=1;
                }
            }
            i++;
        }
        return maxlen;
    }
};
