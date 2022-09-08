class Solution {
public:
    
    bool isnum(string s){
        int len=s.length();
        if(len>1){
            return true;
        }else{
            if(isdigit(s[0])){
                return true;
            }
        }
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(string s:tokens){
            bool num=isnum(s);
            //if s is number push
            if(num){
                stack.push(stoi(s));
            }
            
            //if s is operator,pop 2 nums and perfom op
            else{
                int num2=stack.top();
                stack.pop();
                int num1=stack.top();
                stack.pop();
                switch(s[0]){
                    case '+':stack.push(num1+num2);
                                break;
                    case '-':stack.push(num1-num2);
                                break;
                    case '*':stack.push(num1*num2);
                                break;
                    case '/':stack.push(num1/num2);
                                break;
                    default:break;
                }
            }
        }
        
        return stack.top();
    }
};
