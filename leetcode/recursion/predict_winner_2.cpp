class Solution {
public:
    int max_score(vector<int>nums,int start_index,int end_index,int turn){
       
        if(start_index==end_index){
            int num=nums[start_index];
            if(turn==1){
                return num;
            }else{
                return (-1*num);
            }
        }
        
        //find maximum score difference that player can make if choose start_index element
        int num=nums[start_index];
        int result1=max_score(nums,start_index+1,end_index,(turn%2)+1);
        if(turn==1){
            result1+=num;
        }else{
            result1-=num;
        }
        //find maximum score difference that player can make if choose end_index element
        num=nums[end_index];
        int result2=max_score(nums,start_index,end_index-1,(turn%2)+1);
        if(turn==1){
            result2+=num;
        }else{
            result2-=num;
        }
        //check which result has the maximum difference
        if(turn==1){
            if(result1>=result2){
                return result1;
            }else{
                return result2;
            }
        }else{
            if(result1>=result2){
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
        int score=0;
        int result=max_score(nums,start_index,end_index,turn);
        if(result>=0){
            return true;
        }else{
            return false;
        }
    }
};
