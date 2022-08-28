class Solution {
public:
    
    double power(double num,int exponent){
        if(exponent==0){
            return 1;
        }
        if(exponent==1){
            return num;
        }
        if(num==1){
            return 1;
        }
        if(num==0){
            return 0;
        }
        double value = power(num,exponent/2);
        value=value*value;
        if(exponent%2==0){
            return value;
        }else{
            return value*num;
        }
    }
    
    double myPow(double x, long int n) {
        int exponent;
        if(n>0){
            exponent=n;
        }else{
            exponent=n*-1;
        }
        double x_pow_n = power(x,exponent);
        if(n>0){
            return x_pow_n;
        }else{
            return (1.00000/x_pow_n);
        }
    }
};
