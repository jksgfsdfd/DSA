class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int x:nums){
            arr.push_back(to_string(x));
        }
        
        sort(arr.begin(),arr.end(),specialCompare);
        string ans;
        int size=arr.size();
        for(int i=size-1;i>=0;i--){
            ans+=arr[i];
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
    
    static bool specialCompare(string s1,string s2){
        string pos1=s1+s2;
        string pos2=s2+s1;
        return pos1<pos2;
    }
    
    static int convertToInt(string s){
        int num=0;
        for(int i=0;i<s.size();i++){
                 num=num*10+(s[i]-'0');
        }
        return num;
    }
};
