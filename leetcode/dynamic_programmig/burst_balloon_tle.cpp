class Solution {
public:
    bool broken[300] = {[0 ... 299] = false};
    unordered_map<int,vector<pair<bool *,int>>> state;
    
    bool issame(bool* arr1,bool* arr2){
        for(int i=0;i<300;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    
    int calc(vector<int>&nums,int index){
        int prev=index-1;
        int next=index+1;
        int prev_num=1;
        int next_num=1;
        if(prev>=0){
            while(broken[prev]){
                prev=prev-1;
                if(prev<0){
                    break;
                }
            }
            if(prev>=0){
                prev_num=nums[prev];
            }
        }
        
        if(next<nums.size()){
            while(broken[next]){
                next=next+1;
                if(next>=nums.size()){
                    break;
                }
            }
            if(next<nums.size()){
                next_num=nums[next];
            }
        }
        
        return nums[index] * next_num * prev_num;
    }
    
    int burst(vector<int>& nums,int index){
        
        for(auto bool_arr : state[index]){
            if(issame(bool_arr.first,broken)){
                return bool_arr.second;
            }
        }
        
        int reward = calc(nums,index);
        int future_reward = 0;
        
        for(int i=0;i<nums.size();i++){
            if(broken[i]==false){
                broken[i]=true;
                future_reward=max(future_reward,burst(nums,i));
                broken[i]=false;
            }
        }
        int current_reward = future_reward + reward;
        
        bool * point = new bool[300];
        for(int i=0;i<300;i++){
            point[i]=broken[i];
        }
        state[index].push_back({point,current_reward});
        return current_reward;
    }
    
    int maxCoins(vector<int>& nums) {
        int answer=0;
        for(int i=0;i<nums.size();i++){
            broken[i]=true;
            answer=max(answer,burst(nums,i));
            broken[i]=false;
        }
        return answer;
    }
};
