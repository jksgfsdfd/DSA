class Solution {
public:
    int count=0;
    //int min=INT_MAX;
    int dp[501][501] = {[0 ... 500] = {[0 ... 500] = -1}};
    
    int ways(string &s1,string &s2,int index1,int index2){
        //cout<<min<<endl;
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        
        int operations=0;
        if(index2>=s2.length()){
            if(index1>=s1.length()){
                return 0;
            }else{
                return (s1.length()-index1);
            }
        }
        
        if(index1>=s1.length()){
            if(index2>=s2.length()){
               return 0;
            }else{
                return (s2.length()-index2);
            }
        }
        
        
        if(s1[index1]==s2[index2]){
            operations=ways(s1,s2,index1+1,index2+1);
            return operations;
        }
        //delete element
        
        operations=ways(s1,s2,index1+1,index2);
        
        //replace element
        
        operations=min(operations,ways(s1,s2,index1+1,index2+1));
        
        //insert element
        
        operations=min(operations,ways(s1,s2,index1,index2+1));
        operations++;
        dp[index1][index2]=operations;
        return operations;
        
    }
    
    int minDistance(string s1, string s2) {
        return ways(s1,s2,0,0);
    }
};
