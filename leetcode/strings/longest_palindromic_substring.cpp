class Solution {
public:
    int longest=0;
    pair<int,int> answer;
    string longestPalindrome(string s) {
        int size=s.length();
        if(size==0){
            return "";
        }
        if(size==1){
            return s;
        }
        if(size==2){
            if(s[0]==s[1]){
                return s;
            }else{
                return s.substr(0,1);
            }
        }
        for(int i=0;i<s.length()-1;i++){
            int left=i;
            int right=i+1;
            int count=0;
            while(s[left]==s[right]){
                count+=2;
                left--;
                right++;
                if(left<0 or right>=size){
                    break;
                }
            }
            if(count>longest){
                longest=count;
                answer={left+1,right-1};
            }
            count=1;
            left=i-1;
            right=i+1;
            if(left>=0){
            while(s[left]==s[right]){
                count+=2;
                left--;
                right++;
                if(left<0 or right>=size){
                    break;
                }
            }
            if(count>longest){
                longest=count;
                answer={left+1,right-1};
            }
            }
        }
        string ans = s.substr(answer.first,longest);
        return ans;
    }
};
