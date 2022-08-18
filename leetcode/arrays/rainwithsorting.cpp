class Solution {
public:
    int trap(vector<int>& height) {
       
        //make a sorted array with original indices
        
        vector<pair <int,int> > sorted;
        for(int i=0;i<height.size();i++){
            pair <int,int> a;
            a.first=height[i];
            a.second=i;
            sorted.push_back(a);
        }
        sort(sorted.begin(),sorted.end());

        
        //find the next left and right indices and calculate the area
        int size=height.size();
        int index=sorted[size-1].second;
        int lindex;
        int rindex;
        lindex=rindex=index;
        int trap=0;
        for(int i=size-1;i>=0;i--){
            pair<int,int>a=sorted[i];
            if(a.second>=0 and a.second<lindex){
                //find rain between a.second and lindex
                int area=a.first*(lindex-a.second-1);
                int sum=0;
                for(int j=a.second+1;j<lindex;j++){
                    sum+=height[j];
                }
                lindex=a.second;
                trap+=(area-sum);
            }
            if(a.second<size and a.second>rindex){
                //find rain between a.second and lindex
                int area=a.first*(a.second-rindex-1);
                int sum=0;
                for(int j=rindex+1;j<a.second;j++){
                    sum+=height[j];
                }
                rindex=a.second;
                trap+=(area-sum);
            }
        }
        return trap;
    }
};
