class Solution {
public:
    
    bool valid(string a){
        if(a[0]=='0'){
            return false;
        }
        int b = stoi(a);
        if(1<=b and b<=26){
            return true;
        }
        return false;
    }
    
    int decode(string& s,int index,vector<int>& dp){
        int count1=0,count2=0;
        if(index==1){
            int count=0;
            if(s[0]=='0'){
                return dp[1]=0;
            }
            string str;
            str+=s[index];
            if(valid(str)){
                count++ ;
            }
            str=s.substr(index-1,2);
            if(valid(str)){
                count++;
            }
            return dp[1]=count;
        }
        if(index==0){
            if(s[0]=='0'){
                return dp[0]=0;
            }
            return dp[0]=1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string str;
        str+=s[index];
        if(valid(str)){
            count1 = decode(s,index-1,dp);
        }
        str=s.substr(index-1,2);
        if(valid(str)){
            count2= decode(s,index-2,dp);
        }
        
        return dp[index]=count1+count2;
    }
    
    int numDecodings(string s) {
        int N=s.length();
        vector<int>dp(N,-1);
        return decode(s,N-1,dp);
    }
};
