class Solution {
public:
    unordered_map<string,vector<string>> graph;
    
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
    
    void makegraph(vector<string>& wordList){
        int size = wordList.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(relate(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       bool present = false;
        for(auto ele : wordList){
            if(beginWord==ele){
                present = true;
                break;
            }
        }
        if(present==false){
            wordList.push_back(beginWord);
        }
        makegraph(wordList);
         
        
        //do bfs
        unordered_set<string> seen;
        queue<pair<string,int>> qu;
        qu.push({beginWord,1});
        while(!qu.empty()){
            auto [ele , depth] = qu.front();
            qu.pop();
            if(ele==endWord){
                return depth;
            }
            for(auto word : graph[ele]){
                if(seen.find(word)==seen.end()){
                    qu.push({word,depth+1});
                    seen.insert(word);
                }
            }
            
        }
        return 0;
    }
};
