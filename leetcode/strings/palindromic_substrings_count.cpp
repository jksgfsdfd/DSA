class Solution {
public:
    int countSubstrings(string s) {
        int size=s.length();
        if(size==0){
            return 0;
        }
        if(size==1){
            return 1;
        }
        if(size==2){
            if(s[0]==s[1]){
                return 3;
            }else{
                return 2;
            }
        }
        int count=0;
        for(int i=0;i<s.length()-1;i++){
            count++;
            int left=i;
            int right=i+1;
            while(s[left]==s[right]){
                count++;
                left--;
                right++;
                if(left<0 or right>=size){
                    break;
                }
            }
            left=i-1;
            right=i+1;
            if(left>=0){
            while(s[left]==s[right]){
                count++;
                left--;
                right++;
                if(left<0 or right>=size){
                    break;
                }
            }
            }
        }
        count++;
        return count;
    }
};
