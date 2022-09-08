class Solution {
public:
    void gen_para(vector<string>&answer,int &max,int open_count,int close_count,vector<char>& stack){
        //stop when open_count==max
        if(open_count==max){
            int count=0;
            while(close_count<max){
                stack.push_back(')');
                count++;
                close_count++;
            }
            string s=string(stack.begin(),stack.end());
            answer.push_back(s);
            while(count>0){
                stack.pop_back();
                count--;
            }
            return;
        }
        
        //if open_count==close count gen open 
        if(open_count==close_count){
            stack.push_back('(');
            open_count++;
            gen_para(answer,max,open_count,close_count,stack);
        }else{
            //open_count is greater than close....hence can generate both open and close
            stack.push_back('(');
            open_count++;
            gen_para(answer,max,open_count,close_count,stack);
            stack.pop_back();
            stack.push_back(')');
            open_count--;
            close_count++;
            gen_para(answer,max,open_count,close_count,stack);
        }
        stack.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        int max=n;
        int open_count=0;
        int close_count=0;
        vector<string> answer;
        vector<char> stack;
        
        //till indival count reaches n we have the option to generate ( or ) limited by open_count>=close_count
        
        gen_para(answer,max,open_count,close_count,stack);
        return answer;
    }
};
