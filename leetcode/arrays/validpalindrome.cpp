class Solution {
public:
    bool isPalindrome(string s) {
        string final_string;
        for(char c:s){
            if(isalnum(c)){
                final_string+=tolower(c);
            }
        }
        int i=0;
        int j=final_string.size()-1;
        while(i<=j){
            if(final_string[i]!=final_string[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
