class Solution {
public:
    int arr[301][5001] = {[0 ... 300] = {[0 ... 5000]=-1}};
    
    int newchange(int amount,vector<int>& coins,int start){
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        
        if(arr[start][amount]!=-1){
            return arr[start][amount];
        }
        
        int count = 0;
        for(int i=start;i<coins.size();i++){
            count+=newchange(amount-coins[i],coins,i);
        }
        return arr[start][amount]=count;
    }
    
    int change(int amount, vector<int>& coins) {
        int count = 0;
        if(amount==0){
            return 1;
        }
        for(int i=0;i<coins.size();i++){
            count+=newchange(amount-coins[i],coins,i);
        }
        return count;
    }
};
