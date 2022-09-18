class Solution {
public:
        bool relate(string a , string b){
        int length = a.length();
        int start=0;
        int end = length -1;
        int mid ;
        while(start<end-1){
            mid = (start+end)/2;
            if(start==mid){
                break;
            }
            if(a.substr(start,mid-start)==b.substr(start,mid-start)){
                start = mid;
            }else if(a.substr(mid)==b.substr(mid)){
                end = mid - 1;
            }else{
                return false;
            }
        }
        if(start==end){
            return true;
          }
        
        if(a[start]==b[start]){
            return true;
        }
        
        if(a[end]==b[end]){
            return true;
        }
        
        return false;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordlist;
        for(string word : wordList){
            wordlist.insert(word);
        }
        
        //wordlist.erase(beginWord);
         
        
        //do bfs
        // for(auto ele : wordList){
        //     seen[ele]=false;
        // }
        
        int length = beginWord.length();
        
        queue<pair<string,int>> parent_qu;
        parent_qu.push({beginWord,1});
        unordered_map<string,int> child_map;
        unordered_set<string>visited;
        visited.insert(beginWord);
        //seen[beginWord]=true;
        while(!parent_qu.empty()){
            child_map.clear();
            while(!parent_qu.empty()){
                auto [ele , count] = parent_qu.front();
                cout<<ele<<" "<<count<<endl;
                parent_qu.pop();
                if(ele==endWord){
                    cout<< count;
                }
                for(int i=0;i<length;i++){
                    char c = ele[i];
                    for(int j=0;j<26;j++){
                        ele[i]='a'+j;
                        if(wordlist.find(ele)!=wordlist.end()){
                            if(visited.find(ele)==visited.end()){
                                child_map[ele]=count;
                                visited.insert(ele);
                            }else{
                                if(child_map.count(ele)>0){
                                    child_map[ele]+=count;
                                }
                            }
                        }
                    }
                    ele[i]=c;
                }

            }
            for(auto it : child_map){
                parent_qu.push({it.first,it.second});
            }
        }
        
        return {{}};
    }
};
