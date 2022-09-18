class Solution {
public:
    vector<string> answer;
    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void findans(int index,string &digits,string &poss){
        if(index>=digits.length()){
            answer.push_back(poss);
            return;
        }
        for(char c : map[digits[index]-'0']){
            poss[index]=c;
            findans(index+1,digits,poss);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {    
          
        string poss=digits;
        
        if(digits.length()==0){
            return {};
        }
        
        int index=0;
        findans(index,digits,poss);
        
        return answer;
    }
};
