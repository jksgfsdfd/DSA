class Solution {
public:
    void gen_para(vector<string>&answer,int &max,int open_count,int close_count,string curr){
        //stop when open_count==max
        if(open_count==max){
            while(close_count<max){
                curr+=')';
                close_count++;
            }
            answer.push_back(curr);
            return;
        }
        
        //if open_count==close count gen open 
        if(open_count==close_count){
            string new_curr=curr+'(';
            open_count++;
            gen_para(answer,max,open_count,close_count,new_curr);
        }else{
            //open_count is greater than close....hence can generate both open and close
            string new_curr=curr+'(';
            open_count++;
            gen_para(answer,max,open_count,close_count,new_curr);
            new_curr=curr+')';
            open_count--;
            close_count++;
            gen_para(answer,max,open_count,close_count,new_curr);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int max=n;
        int open_count=0;
        int close_count=0;
        vector<string> answer;
        
        //till indival count reaches n we have the option to generate ( or ) limited by open_count>=close_count
        
        gen_para(answer,max,open_count,close_count,"");
        return answer;
    }
};
