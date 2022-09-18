class Solution {
public:
    typedef pair<int, char> pi;
    int leastInterval(vector<char>& tasks, int n) {
        //make map for all elements and keep track of time
        unordered_map<char,int> map;
        priority_queue<pi> heap;
        for(char a : tasks){
            if(map.find(a)!=map.end()){
                map[a]++;
            }else{
                map[a]=1;
            }
        }
        for(auto it : map){
            heap.push({it.second,it.first});
        }
        int time=0;
        queue<pair<char,int>> not_possible;
        while(!map.empty()){
            if(!not_possible.empty()){
                while(not_possible.front().second+n<time){
                    int count = map[not_possible.front().first];
                    heap.push({count,not_possible.front().first});
                    not_possible.pop();
                    if(not_possible.empty()){
                        break;
                    }
                }
            }
            if(!heap.empty()){
                pair<int,char> ele = heap.top();
                if(map[ele.second]==1){
                    map.erase(ele.second);
                }else{
                    map[ele.second]--;
                    not_possible.push({ele.second,time});
                }
                heap.pop();
            }
            time++;
        }
        return time;
    }
};
