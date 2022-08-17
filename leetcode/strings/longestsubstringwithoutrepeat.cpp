class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i=0;
        int j=0;
        int length=s.length();
        if(length<2){
            return length;
        }
        set.insert(s[j]);
        int count=1;
        int max=1;
        while(j<length-1){
            j++;
            while(set.find(s[j])==set.end()){
                set.insert(s[j]);
                count++;
                j++;
                if(j==length){
                    if(count>max){
                       max=count;
                    }
                    return max;
                }
            }
            if(count>max){
                max=count;
            }
            
            //update i to point to the next element after the repeating one
            while(s[i]!=s[j]){
                set.erase(s[i]);
                i++;
            }
            
            i++;
            count=j-i+1;
            
        }
        return max;
    }
};
