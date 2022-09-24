class Solution {
public:
    
    int s_length;
    int t_length;
    string s;
    string t;
    
    int dp[1001][1001] = {[0 ... 1000] = {[0 ... 1000] = -1}};
    
    int run_count(int s_index,int t_index){
        
        if(dp[s_index][t_index]!=-1){
            return dp[s_index][t_index];
        }
        int curr_count=0;
        for(int i=s_index;i<s_length-(t_length-t_index-1);i++){
            if(t[t_index]==s[i]){
                if(t_index==t_length-1){
                    curr_count++;
                }else{
                    curr_count+=run_count(i+1,t_index+1);
                }
            }
        }
        dp[s_index][t_index]=curr_count;
        return curr_count;
    }
    
    int numDistinct(string _s, string _t) {
        s=_s;
        t=_t;
        s_length=s.length();
        t_length=t.length();
        int count=run_count(0,0);
        return count;
    }
};
