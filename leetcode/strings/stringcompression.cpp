class Solution {
public:
    int compress(vector<char>& chars) {
        int count=1;
        int j=0;
        for(int i=1;i<chars.size();i++){
            //write the last condition here
            
            //if previous element is same
            if(chars[i-1]==chars[i]){
                count++;
                if(i==chars.size()-1){
                    //write the count
                    string cnt=to_string(count);
                    char *a=(char *)cnt.c_str();
                    while(*a){
                        j++;
                        chars[j]=*a;
                        a++;
                    }
                }
            }else{
            //if previous element is diff
                if(count==1){
                    j++;
                    chars[j]=chars[i];
                }else{
                    //write count
                    string cnt=to_string(count);
                    char *a=(char *)cnt.c_str();
                    while(*a){
                        j++;
                        chars[j]=*a;
                        a++;
                    }
                    //wite the new char and set count to 1
                    j++;
                    chars[j]=chars[i];
                    count=1;
                }
            }
        }
        
        return (j+1);
    }
};
