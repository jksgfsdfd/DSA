class Solution {
public:
    vector<vector<string>> possible;
    vector<string> currentlist;
    int count=0;
    vector<string> answer;
    bool found = false;
    
    void dfs(unordered_map<string,vector<pair<string,bool>>>& graph,string source,int &N){
        for(auto &[dest , used] : graph[source]){
            if(found==true){
                return;
            }
            if(used==false){
                count++;
                currentlist.push_back(dest);
                if(count==N+1){
                    answer=currentlist;
                    found = true;
                    return;
                }
                used=true;
                dfs(graph,dest,N);
                used=false;
                currentlist.pop_back();
                count--;
            }
        }
    }
    
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int N = tickets.size();
        unordered_map<string,vector<pair<string,bool>>> graph;
        for(auto edge : tickets){
            graph[edge[0]].push_back({edge[1],false});
        }
        
        for(auto &[source , dests] : graph){
            sort(dests.begin(),dests.end());
        }
        
        string start = "JFK";
        currentlist.push_back(start);
        count=1;
        dfs(graph,start,N);    
        return answer;
    }
};
