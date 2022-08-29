class Solution {
public:
    string simplifyPath(string path) {
        int len=path.length();
        vector<string> stack;
        
        string slash="/";
        string name;
        stack.push_back("/");
        int sp=0;
        int index=0;
        char c;
        for(int i=1;i<len;i++){
            c=path[i];
            if(c=='/'){
                if(stack.back()==slash){
                    continue;
                }else{
                    //sp++;
                    stack.push_back(slash);
                }
            }
            else if(isalnum(c) or c=='_'){
                name.clear();
                while(c!='/' ){
                    name+=c;
                    i++;
                    if(i==len){
                        break;
                    }
                    c=path[i];
                }
                stack.push_back(name);
                i--;
            }
            else if(c=='.'){
                int count=0;
                while(c=='.'){
                    count++;
                    i++;
                    if(i==len){
                        break;
                    }
                    c=path[i];
                }
                if(c=='/' or i==len){
                    if(count==1){
                        i--;
                        continue;
                    }
                    else if(count==2)
                    {
                        stack.pop_back();
                        if(stack.size()!=0)
                        {
                            stack.pop_back();
                        }
                        else
                        {
                            stack.push_back(slash);
                        }
                        i--;
                    }
                    else
                    {
                        name.clear();
                        while(count--){
                            name+='.';
                        }
                        while(c!='/' and i<len){
                            name+=c;
                            i++;
                            if(i==len){
                                break;
                            }
                            c=path[i];
                        }
                        i--;
                        stack.push_back(name);    
                    }
                }
                else
                {
                    name.clear();
                    while(count--){
                        name+='.';
                    }
                    while(c!='/' and i<len){
                        name+=c;
                        i++;
                        if(i==len){
                            break;
                        }
                        c=path[i];
                    }
                    i--;
                    stack.push_back(name);
                
                }
            }
        }
        if(stack.size()>1){
            if(stack.back()==slash){
                stack.pop_back();
            }
        }
        string answer;
        for(string a:stack){
            answer+=a;
        }
        return answer;
    }
};
