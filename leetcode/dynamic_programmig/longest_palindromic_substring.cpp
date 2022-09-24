class Solution {
public:
    int len_longest=0;
    int x=-1;
    int y=-1;
    int8_t dp[1000][1000] = {[0 ... 999] = {[0 ... 999] = -1}};
    
    void longestpalin(string &s,int end){
        for(int i=0;i<=end;i++){
            if(checkpalin(s,i,end)){
                if(end-i+1>len_longest){
                    len_longest=end-i+1;
                    x=i;
                    y=end;
                }
                return ;
            }
        }
        return ;
    }
    
    bool checkpalin(string &s,int start,int end){
        if(start==end){
            return true;
        }
        if(start==end-1){
            if(s[start]==s[end]){
                return true;
            }
            return false;
        }
        
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(checkpalin(s,start+1,end-1)){
            if(s[start]==s[end]){
                dp[start][end]=1;
                return true;
            }
        }
        dp[start][end]=0;
        return false;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        for(int i=0;i<=n-1;i++){
            longestpalin(s,i);
        }
        //cout<<len_longest<<" "<<s.substr(x,len_longest);
        return s.substr(x,len_longest);
    }
};
