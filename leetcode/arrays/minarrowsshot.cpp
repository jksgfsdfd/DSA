class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair <int,int>> starts;
        for(int i=0;i<points.size();i++){
            starts.push_back({points[i][0],i});
        }
        
        sort(starts.begin(),starts.end());
       
        
        int size=starts.size();
        if(size==0){
            return 0;
        }
        int start=starts[0].first;
        int index=starts[0].second;
        int end=points[index][1];
        int arrows=0;
        for(int i=0;i<size;i++){
            if(starts[i].first<=end){
                start=starts[i].first;
                index=starts[i].second;
                if(points[index][1]<=end){
                    end=points[index][1];
                }
            }else{
                arrows++;
                start=starts[i].first;
                index=starts[i].second;
                end=points[index][1];
            }
            if(i==size-1){
                arrows++;
            }
        }
        return arrows;
    }
};
