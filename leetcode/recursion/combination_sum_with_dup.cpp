class Solution {
public:
    vector<vector<int>> findsubs(unordered_map<int,int> map,vector<vector<int>>& lesser,int target){
        vector<vector<int>> answer;
        for(auto it : map){
            int size = lesser.size();
            int count = it.second;
            int value = it.first;
            for(int m=1;m<=count;m++){
                vector<int> temp;
                for(int i=0;i<size;i++){
                    temp = lesser[i];
                    if(value*m + temp[0]< target){
                        temp[0] = temp[0] + value*m;
                        for(int j=1;j<=m;j++){
                            temp.push_back(value);
                        }
                        lesser.push_back(temp);
                    }else if(value*m + temp[0] == target){
                        temp[0] = target;
                        for(int j=1;j<=m;j++){
                            temp.push_back(value);
                        }
                        vector<int> ans(temp.begin()+1,temp.end());
                        answer.push_back(ans);
                    }
                    
                }
            }
        }
        return answer;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int,int> map;
        for(int i : candidates){
            if(map.find(i)==map.end()){
                map[i]=1;
            }else{
                map[i]++;
            }
        }
        vector<vector<int>> lesser = {{0}};
        vector<vector<int>> answer = findsubs(map,lesser,target);
        return answer;
    }
};
