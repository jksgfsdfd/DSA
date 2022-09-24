class Solution {
public:
    int findword(string s,string word){
        int W = word.length();
        int N = s.length();
        if(N<W){
            return -1;
        }
        if(word==s.substr(0,W)){    
            return W;
        }
        return -1;
    }
    
    unordered_map<string,bool>dp;
    
    bool makeword(string s,vector<string>& wordDict){
        if(s==""){
            return true;
        }
         if(dp.count(s)){
             return dp[s];
         }
        bool possible;
        for(string word : wordDict){
            int new_start = findword(s,word);
            if(new_start==-1){
                continue;
            }
           // cout<<start<<" "<<end;
            string str;
            str+=s.substr(new_start);
           // cout<<str<<endl;
            possible = makeword(str,wordDict);
            if(possible==true){
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return makeword(s,wordDict);
    }
};
