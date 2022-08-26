class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        for(char c:s){
            if(map.find(c)!=map.end()){
                map[c]++;
            }else{
                map[c]=1;
            }
        }
        for(char c:t){
            if(map.find(c)!=map.end()){
                map[c]--;
                if(!map[c]){
                    map.erase(c);
                }
            }else{
                return false;
            }
        }
        if(map.size()){
            return false;
        }else{
            return true;
        }
    }
};
