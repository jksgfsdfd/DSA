class Solution {
public:
    int arr[102][102]={[0 ... 101]={[0 ... 101]=-1}};
    string s1;
    string s2;
    string s3;
    bool inter(int len1,int len2,int len3){
        if(len3==0){
            if(len1==len2){
                if(len1==0){
                    return true;
                }
            }
            return false;
        }
        
        if(arr[len1][len2]!=-1){
            return arr[len1][len2];
        }
        
        if(len1==0){
            if(s2.substr(0,len2)==s3.substr(0,len3)){
                return arr[len1][len2]=true;
            }else{
                return arr[len1][len2]=false;
            }
        }
        if(len2==0){
            if(s1.substr(0,len1)==s3.substr(0,len3)){
                return arr[len1][len2]=true;
            }else{
                return arr[len1][len2]=false;
            }
        }
        
        
        if(s3[len3-1]==s1[len1-1] and s3[len3-1]==s2[len2-1]){
            len3--;
            return arr[len1][len2]=(inter(len1-1,len2,len3) or inter(len1,len2-1,len3));
        }else if(s3[len3-1]==s1[len1-1]){
            len3--;
            len1--;
            return arr[len1][len2]=inter(len1,len2,len3);
        }else if(s3[len3-1]==s2[len2-1]){
            len3--;
            len2--;
            return arr[len1][len2]=inter(len1,len2,len3);
        }else{
            return arr[len1][len2]=false;
        }
    }
    
    bool isInterleave(string _s1, string _s2, string _s3) {
       
        s1=_s1;
        s2=_s2;
        s3=_s3;
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        return inter(len1,len2,len3);
        /* if(s3==""){
            if(s1==s2){
                if(s1==""){
                    return true;
                }
            }
            return false;
        }
        if(s3.back()==s1.back() and s3.back()==s2.back()){
            s3.pop_back();
            string str1=s1;
            string str2=s2;
            str1.pop_back();
            str2.pop_back();
            return (isInterleave(str1,s2,s3) or isInterleave(s1,str2,s3));
        }else if(s3.back()==s1.back()){
            s3.pop_back();
            s1.pop_back();
            return isInterleave(s1,s2,s3);
        }else if(s3.back()==s2.back()){
            s3.pop_back();
            s2.pop_back();
            return isInterleave(s1,s2,s3);
        }else{
            return false;
        } */
    }
};
