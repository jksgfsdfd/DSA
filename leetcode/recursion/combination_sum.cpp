class Solution {
public:
    vector<vector<int>> csum (vector<int>& candidates,int target,vector<vector<int>>& lesser,int index){
        if(index==candidates.size()){
            lesser={{0}};
            return {};
        }
        
        vector<vector<int>> answer = csum(candidates,target,lesser,index+1);
        int size = lesser.size();
        for(int i=0;i<size;i++){
            if(lesser[i][0]+candidates[index]==target){
                vector<int> temp(lesser[i].begin()+1,lesser[i].end());
                temp.push_back(candidates[index]);
                answer.push_back(temp);
            }else if(lesser[i][0]+candidates[index]<target){
                vector<int> temp(lesser[i].begin(),lesser[i].end());
                temp.push_back(candidates[index]);
                temp[0]+=candidates[index];
                while(temp[0]<target){
                    lesser.push_back(temp);
                    temp.push_back(candidates[index]);
                    temp[0]+=candidates[index];      
                }
                if(temp[0]==target){
                    vector<int> hello(temp.begin()+1,temp.end());
                    answer.push_back(hello);
                }
            }
        }
        return answer;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> lesser;
        int index=0;
        vector<vector<int>> answer = csum(candidates,target,lesser,index);
        return answer;
    }
};
