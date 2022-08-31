class Solution {
public:
    string find_freq_map(string s){
        string answer=s;
        sort(answer.begin(),answer.end());
        return answer;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> answer;
        
        for(string s:strs){
            string freq_map = find_freq_map(s);
            map[freq_map].push_back(s);
        }
        
        for(auto it:map){
            answer.push_back(it.second);
        }
        return answer;
    }   
};
