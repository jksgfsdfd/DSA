class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size=position.size();
        vector<float>time;
        vector<pair<int,int>> pos_speed;
        for(int i=0;i<size;i++){
            pos_speed.push_back({position[i],speed[i]});
        }
        sort(pos_speed.begin(),pos_speed.end());
        for(int i=0;i<size;i++){
            time.push_back(float(target-pos_speed[i].first)/float(pos_speed[i].second));
        }
        
        //a car starting at a lower position will form a fleet with a car which is higher in starting position but takes more time to finish
        stack<float> fleet;
        int fleet_count=1;
        fleet.push(time[size-1]);
        for(int i=size-2;i>=0;i--){
            if(time[i]>fleet.top()){
                fleet.push(time[i]);
                fleet_count++;
            }
        }
        return fleet_count;
    }
};
