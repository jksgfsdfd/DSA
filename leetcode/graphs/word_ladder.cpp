
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

        queue<pair<string,int>> qu;
        qu.push({beginWord,1});
        //seen[beginWord]=true;
        while(!qu.empty()){
            auto [ele , depth] = qu.front();
            qu.pop();
            if(ele==endWord){
                return depth;
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
        return 0;
    }
};
