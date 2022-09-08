class TimeMap {
    unordered_map<string,vector<pair<int,string>>> full_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int,string> new_ele={timestamp,value};
        full_map[key].push_back(new_ele);
       /* for(auto x:time_map[key]){
            cout<<key<<" "<<x<<endl;
        }*/
    }
    
    string get(string key, int timestamp) {
        if(full_map.find(key)==full_map.end()){
            return "";
        }
        //vector<pair<int,string>> times(full_map[key]);
        int start_index=0;
        int end_index=full_map[key].size()-1;
        int mid;
        while(start_index<=end_index){
            mid=(start_index+end_index)/2;
            if(timestamp==full_map[key][mid].first){
                return full_map[key][mid].second;
            }else if(timestamp>full_map[key][mid].first){
                start_index=mid+1;
            }else{
                end_index=mid-1;
            }
        }
        if(end_index<0){
            return "";
        }
        return full_map[key][end_index].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
