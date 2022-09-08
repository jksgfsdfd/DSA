class Solution {
public:
    bool valid(unordered_map<char,int> map,int left,int right,int k){
        int max=INT_MIN;
        for(auto it:map){
            if((it.second)>max){
                max=it.second;
            }
        }
        if(k+max>=(right-left+1)){
            return true;
        }else{
            return false;
        }
    }
    
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int count=0;
        int max=0;
        int len=s.length();
        unordered_map<char,int> map;
        while(right<len){
            //check if after adding this element window is still valid
            if(map.find(s[right])!=map.end()){
                map[s[right]]++;
            }else{
                map[s[right]]=1;
            }
            if(valid(map,left,right,k)){
                count++;
                if(count>max){
                    max=count;
                }
            }else{
                while(!valid(map,left,right,k)){
                    map[s[left]]--;
                    left=left+1;
                    count--;
                }
                count++;
            }
            right++;
        }
        return max;
    }
};
