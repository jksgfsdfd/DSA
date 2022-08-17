class Solution {
public:
    bool detectCapitalUse(string word) {
        int length=word.length();
        if(length<2){
            return true;
        }
        if(islower(word[0])){
            for(int i=1;i<length;i++){
                if(isupper(word[i])){
                    return false;
                }
            }
            return true;
        }
        if(islower(word[1])){
            for(int i=2;i<length;i++){
                if(isupper(word[i])){
                    return false;
                }
            }
            return true;
        }else{
            for(int i=2;i<length;i++){
                if(islower(word[i])){
                    return false;
                }
            }
            return true;
        }
        
    }
};
