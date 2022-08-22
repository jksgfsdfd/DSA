class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length()==0){
            return t;
        }
        if(t.length()==1){
            for(char c:s){
                if(c==t[0]){
                    return t;
                }
            }
            return "";
        }
        //make hashmap of string t
        unordered_map<char,int> input_map;
        for(char c:t){
            if(input_map.count(c)){
                input_map[c]++;
            }else{
                input_map[c]=1;
            }
        }
       
        
        int r_index=0;
        int l_index=0;
        int check_size=t.length();
        int size=s.length();
        
        //initialise l_index to first element among the hashmap
        for(;l_index<=size-check_size;l_index++){
            if(input_map.count(s[l_index])!=0){
                break;
            }
        }    
        
        
        if(l_index>size-check_size){
            return "";
        }
        
        r_index=l_index+1;
        
        int min_r_index=0;
        int min_l_index=0;
        int min_len=INT_MAX;
        unordered_map<char,int> map;
        map[s[l_index]]=1;
        char c;
        bool present;
        while(r_index<size){
            //if present then update length and l_index else increment r_index
          
            c=s[r_index];
            if(input_map.count(c)!=0){
                if(map.count(c)){
                    map[c]++;
                 }else{
                    map[c]=1;
                 }
            }
            present=true;
         while(present==true){
            for(auto x:input_map){
                if(map.count(x.first)==0){
                    present=false;
                    break;
                }
                if(x.second>map[x.first]){
                    present=false;
                    break;
                }
            }
            if(present){
                if(r_index-l_index+1<=min_len){
                    min_len=r_index-l_index+1;
                    min_r_index=r_index;
                    min_l_index=l_index;
                }
                map[s[l_index]]--;
                l_index++;
                //increment l till next element in input_map
                while(l_index<=r_index){
                    if(input_map.count(s[l_index])!=0){
                       break;
                    }
                    l_index++;
                }
            }
         }
            r_index++;
        }
        if(min_len==INT_MAX){
            return "";
        }
        string substr=s.substr(min_l_index,min_len);
        return substr;
    }
};
