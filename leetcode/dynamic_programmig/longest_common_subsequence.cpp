class Solution {
public:
    int arr[1001][1001] = {[0 ... 1000] = {[0 ... 1000]  = -1}};
    string text1;
    string text2;
    
    int LCS(int index1,int index2){
        if(index1==-1 or index2==-1){
            return 0;        
        }
        if(arr[index1][index2]!=-1){
            return arr[index1][index2];
        }
        if(text1[index1]==text2[index2]){
            return arr[index1][index2]=(1 + LCS(index1-1,index2-1));  
        }
        return arr[index1][index2]=max(LCS(index1-1,index2),LCS(index1,index2-1));
    }
        
        
    int longestCommonSubsequence(string _text1, string _text2) {
        text1=_text1;
        text2=_text2;
        int index1=text1.size()-1;
        int index2=text2.size()-1;
        return LCS(index1,index2);
        /*
        int count=0;
        if(text1.size()==0 or text2.size()==0){
            return 0;
        }
        int x = text1.length();
        int y = text2.length();
        if(arr[x][y]!=-1){
            return arr[x][y];
        }
        
        if(text1.back()==text2.back()){
            count++;
            string temp1=text1;
            string temp2=text2;
            temp1.pop_back();
            temp2.pop_back();
            int path = longestCommonSubsequence(temp1,temp2);
            return arr[x][y]count+path;
        }
        string temp1=text1;
        string temp2=text2;
        temp1.pop_back();
        int path1 = longestCommonSubsequence(temp1,temp2);
        temp1=text1;
        temp2=text2;
        temp2.pop_back();
        int path2 = longestCommonSubsequence(temp1,temp2);
        return arr[x][y]=max(path1,path2);
        */
    }
};
