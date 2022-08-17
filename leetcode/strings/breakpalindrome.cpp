class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length=palindrome.length();
        if(length<2){
            return "";
        }
        
        for(int i=0;i<length;i++){
            if(palindrome[i]!='a'){
                if((length%2)!=0 and i==((length+1)/2)-1){
                    continue;
                }
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[length-1]='b';
        return palindrome;
    }
};
