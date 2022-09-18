class Solution {
public:
    vector<string> answer;
    vector<string> map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void findans(const string& digits,int index,string& currentList){
        if(index==digits.size()){
            answer.push_back(currentList);
            return;
        }
        int map_index=digits[index]-'0'-2;
        for(char c: map[map_index]){
            currentList[index]=c;
            findans(digits,index+1,currentList);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        string currentList(digits);
        int index=0;
        findans(digits,index,currentList);
        return answer;
    }
};
