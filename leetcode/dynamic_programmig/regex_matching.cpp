class Solution {
public:
    
    int8_t dp[20][30] = {[0 ... 19] = {[0 ... 29] = -1}};
    
    bool states(string &s,string &p,int index_s,int index_p){
        if(index_s>=s.length()){
            if(index_p>=p.length()){
                return true;
            }else if(p[index_p+1]=='*' and index_p+1==p.length()-1){
                return true;
            }else if(p[index_p+1]=='*'){
                return states(s,p,index_s,index_p+2);
            }else{
                return false;
            }
        }
        
        
        if(index_p>=p.length()){
            return false;
        }

        if(dp[index_s][index_p]!=-1){
            return dp[index_s][index_p];
        }
        
        if(p[index_p+1]=='*'){
            if(p[index_p]=='.'){
                bool poss1=states(s,p,index_s,index_p+2);
                bool poss2=states(s,p,index_s+1,index_p);
                
                return dp[index_s][index_p]=(poss1 or poss2);
            }else{
                if(s[index_s]==p[index_p]){
                    bool poss1=states(s,p,index_s,index_p+2);
                    bool poss2=states(s,p,index_s+1,index_p);
                    return dp[index_s][index_p]=(poss1 or poss2);
                }else{
                    return dp[index_s][index_p]=states(s,p,index_s,index_p+2);
                }
            }
        }else{
            if(p[index_p]=='.'){
                return dp[index_s][index_p]=states(s,p,index_s+1,index_p+1);
            }else{
                if(s[index_s]==p[index_p]){
                    return dp[index_s][index_p]=states(s,p,index_s+1,index_p+1);
                }else{
                    return dp[index_s][index_p]=false;
                }
            }
        }
    }
    
    bool isMatch(string s, string p) {
        return states(s,p,0,0);
    }
};
