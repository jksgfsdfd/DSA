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

    vector<vector<string>> answer;
    vector<string> currentlist;
    unordered_map<string,pair<int,bool>>visited;
    
    void dfs(unordered_set<string>& wordlist,string ele,string endWord,int length){
        if(length==1){
            if(ele==endWord){
                answer.push_back(currentlist);
                for(auto str:currentlist){
                    visited[str].second=true;
                }
            }else{
                for(auto str:currentlist){
                    if(visited[str].second!=true){
                        visited[str].second=false;
                    }
                }
                return;
            }
        }
        for(int i=0;i<endWord.length();i++){
                char c = ele[i];
                for(int j=0;j<26;j++){
                    ele[i]='a'+j;
                    if(wordlist.find(ele)!=wordlist.end() and visited.find(ele)==visited.end()){
                        visited[ele].first=length;
                        currentlist.push_back(ele);
                        dfs(wordlist,ele,endWord,length-1);
                        currentlist.pop_back();
                        //visited.erase(ele);
                    }else if(wordlist.find(ele)!=wordlist.end()){
                        if(length>visited[ele].first){
                            visited[ele].first=length;
                            currentlist.push_back(ele);
                            dfs(wordlist,ele,endWord,length-1);
                            currentlist.pop_back();
                        }else if(length==visited[ele].first){
                            if(visited[ele].second==false){
                                continue;
                            }else{
                                currentlist.push_back(ele);
                                dfs(wordlist,ele,endWord,length-1);
                                currentlist.pop_back();
                            }   
                        }else{
                            continue;
                        }
                    }
                }
                ele[i]=c;
            }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordlist;
        for(string word : wordList){
            wordlist.insert(word);
        }
        
        wordlist.erase(beginWord);
         
        
        //do bfs
        // for(auto ele : wordList){
        //     seen[ele]=false;
        // }
        
        int length = beginWord.length();
        int dist;
        
        unordered_set<string> newlist = wordlist;
        
        queue<pair<string,int>> qu;
        qu.push({beginWord,1});

        while(!qu.empty()){
            auto [ele , depth] = qu.front();
            qu.pop();
            if(ele==endWord){
                dist=depth;
            }
            for(int i=0;i<length;i++){
                char c = ele[i];
                for(int j=0;j<26;j++){
                    ele[i]='a'+j;
                    if(wordlist.find(ele)!=wordlist.end()){
                        qu.push({ele,depth+1});
                        wordlist.erase(ele);
                    }
                }
                ele[i]=c;
            }
            
        }
        
        cout<<dist;
        //look for path from beginword
        // newlist.erase(endWord);
        // newlist.insert(beginWord);
        currentlist.push_back(beginWord);
        dfs(newlist,beginWord,endWord,dist);
        // for(auto &arr : answer){
        //     reverse(arr.begin(),arr.end());
        // }
        return answer;
    }
};
