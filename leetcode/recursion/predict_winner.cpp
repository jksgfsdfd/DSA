class Solution {
public:
    pair<int,int> max_score(vector<int>nums,int start_index,int end_index,int turn,pair<int,int>scores){
       
        if(start_index==end_index){
            int num=nums[start_index];
            if(turn==1){
                scores.first+=num;
                return scores;
            }else{
                scores.second+=num;
                return scores;
            }
        }
        
        //find maximum score difference that player can make if choose start_index element
        int num=nums[start_index];
        pair<int,int> curr_scores=scores;
        if(turn==1){
            curr_scores.first+=num;
        }else{
            curr_scores.second+=num;
        }
        pair<int,int>result1=max_score(nums,start_index+1,end_index,(turn%2)+1,curr_scores);
        //find maximum score difference that player can make if choose end_index element
        num=nums[end_index];
        curr_scores=scores;
        if(turn==1){
            curr_scores.first+=num;
        }else{
            curr_scores.second+=num;
        }
        pair<int,int>result2=max_score(nums,start_index,end_index-1,(turn%2)+1,curr_scores);
        
        //check which result has the maximum difference
        int result1_diff=result1.first-result1.second;
        int result2_diff=result2.first-result2.second;
        
        if(turn==1){
            if(result1_diff>=result2_diff){
                return result1;
            }else{
                return result2;
            }
        }else{
            if(result1_diff>=result2_diff){
                return result2;
            }else{
                return result1;
            }
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int start_index=0;
        int end_index=nums.size()-1;
        int turn=1;
        pair<int,int>scores;
        scores.first=0;
        scores.second=0;
        pair<int,int>result=max_score(nums,start_index,end_index,turn,scores);
        if(result.first>=result.second){
            return true;
        }else{
            return false;
        }
    }
};
