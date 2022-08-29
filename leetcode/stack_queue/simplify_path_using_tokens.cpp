class Solution {
public:
    string simplifyPath(string path) {
        stringstream istream(path);
        string token;
        vector<string> tokens;
        while(getline(istream,token,'/')){
            tokens.push_back(token);
        }
        vector<string> stack;
        int size=tokens.size();
        for(int i=0;i<size;i++){
            if(tokens[i]=="."){
                continue;
            }else if(tokens[i]==".."){
                if(stack.empty()){
                    continue;
                }else{
                    stack.pop_back();
                }
            }else if(tokens[i]==""){
                continue;
            }else{
                stack.push_back(tokens[i]);
            }
        }
        string answer;
        size=stack.size();
        if(size==0){
            return "/";
        }
        for(int i=0;i<size;i++){
            answer+='/';
            answer+=stack[i];
        }
        return answer;
    }
};
