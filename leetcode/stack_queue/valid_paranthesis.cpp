class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            switch(c){
                case '}':
                    if(!stk.size()){
                        return false;
                    }
                    if(stk.top()=='{'){
                        stk.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                case ')':
                    if(!stk.size()){
                        return false;
                    }
                    if(stk.top()=='('){
                        stk.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                case ']':
                    if(!stk.size()){
                        return false;
                    }
                    if(stk.top()=='['){
                        stk.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                default:
                    stk.push(c);
                    continue;
            }
        }
        if(stk.size()){
            return false;
        }
        return true;
    }
};
