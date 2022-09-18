class Solution {
public:
    void findsubs(unordered_map<int,int> map,vector<vector<int>>& answer){
        for(auto it : map){
            int size = answer.size();
            int count = it.second;
            int value = it.first;
            while(count){
                vector<int> temp;
                for(int i=0;i<size;i++){
                    temp = answer[i];
                    for(int j=1;j<=count;j++){
                        temp.push_back(value);
                    }
                    answer.push_back(temp);
                }
                count--;
            }
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i : nums){
            if(map.find(i)==map.end()){
                map[i]=1;
            }else{
                map[i]++;
            }
        }
        vector<vector<int>> answer = {{}};
        findsubs(map,answer);
        return answer;
    }
};
