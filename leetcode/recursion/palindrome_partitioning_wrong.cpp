class Solution {
public:
    void findanswer(vector<vector<string>>& answer,vector<string> palin,int start){
        int size = palin.size();
        
        //the property of finding palinromes is wrong
        
        int new_start=start-2;
        if(start-2<0){
            new_start=0;
        }
        for(int i=new_start;i<size-2;i++){
            if(palin[i]==palin[i+1]){
                vector<string> new_palin(size-1);
                for(int m=0;m<i;m++){
                    new_palin[m]=palin[m];
                }
                new_palin[i]=palin[i]+palin[i+1];
                for(int m=i+1;m<size-1;m++){
                    new_palin[m]=palin[m+1];
                }
                answer.push_back(new_palin);
                findanswer(answer,new_palin,i);
            }
            if(palin[i]==palin[i+2]){
                vector<string> new_palin(size-2);
                for(int m=0;m<i;m++){
                    new_palin[m]=palin[m];
                }
                new_palin[i]=palin[i]+palin[i+1]+palin[i+2];
                for(int m=i+1;m<size-2;m++){
                    new_palin[m]=palin[m+2];
                }
                answer.push_back(new_palin);
                findanswer(answer,new_palin,i);
                }
        }
        if(size>=2){
            if(palin[size-2]==palin[size-1]){
                vector<string> new_palin(size-1);
                for(int m=0;m<size-2;m++){
                    new_palin[m]=palin[m];
                }
                new_palin[size-2]=palin[size-2]+palin[size-1];
                answer.push_back(new_palin);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> palin;
        for(char c : s){
            string str;
            str+=c;
            palin.push_back(str);
        }
        answer.push_back(palin);
        
        int start=0;
        findanswer(answer,palin,start);
        return answer;
    }
};
