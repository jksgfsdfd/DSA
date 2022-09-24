class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if(n==1){
            return a;
        }
        if(n==2){
            return 2;
        }
        int c;
        n=n-2;
        while(n>0){
            c=a+b;
            a=b;
            b=c;
            n--;
        }
        return c;
        
    }
};
