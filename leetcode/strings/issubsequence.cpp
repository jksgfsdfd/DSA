class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        for(int i=0;i<s.size();){
            if(j==t.size()){
                return false;
            }
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
                if(j==t.size()){
                    return false;
                }
            }
        }
        return true;
    }
};
