class Solution {
public:
    vector<vector<string>> answer;
    
    bool isPalin(string s){
        for(int i=0,j=s.length()-1;i<=j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    
    void findans(const string & s , int index , vector<string> & currentList){
        if(index>=s.size()){
            answer.push_back(currentList);
            return;
        }
        string st;
        for(int i=index;i<s.size();i++){
            st += s[i];
            if(isPalin(st)){
                currentList.push_back(st);
                findans(s,i+1,currentList);
                currentList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int index=0;
        vector<string> currentPartition;
        findans(s,0,currentPartition);
        return answer;
    }
};
