class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string check=s1;
        string sub;
        if(s1.length()>s2.length()){
            return false;
        }
        unordered_map<char,int> map_1;
        for(char c:s1){
            if(map_1.find(c)==map_1.end()){
                map_1[c]=1;
            }else{
                map_1[c]++;
            }
        }
        unordered_map<char,int> map_2;
        int len=s2.length();
        int win_len=s1.length();
        int left=0;
        int right=win_len-1;
        
        for(int i=left;i<=right;i++){
            char c=s2[i];
            if(map_2.find(c)==map_2.end()){
                map_2[c]=1;
            }else{
                map_2[c]++;
            }
        }
        
        if(map_1==map_2){
            return true;
        }
        right++;
        
        while(right<len){
            char c_add=s2[right];
            char c_remove=s2[left];
            left++;
            //add right ele
            if(map_2.find(c_add)==map_2.end()){
                map_2[c_add]=1;
            }else{
                map_2[c_add]++;
            }
            //remmove left ele
             map_2[c_remove]--;
             if(map_2[c_remove]==0){
                map_2.erase(c_remove);
             }
            if(map_1==map_2){
                return true;
            }
            right++;
        }
        return false;
    }
};
