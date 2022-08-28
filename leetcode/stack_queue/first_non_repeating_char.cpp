//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string answer;
            queue<char> que;
            unordered_map<char,int> check;
            for(char c:A){
                if(check.find(c)!=check.end()){
                    check[c]++;
                }else{
                    check[c]=1;
                    que.push(c);
                }
                
                while(que.size()){
                    if(check[que.front()]==1){
                        answer+=que.front();
                        break;
                    }else{
                        que.pop();
                    }
                }
                
                if(que.size()==0){
                    answer+='#';
                }
                
            }
            return answer;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
