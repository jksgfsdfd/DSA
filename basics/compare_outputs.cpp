
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> my_out={"(()())()","((()()))","()()()()","()(()())","((()))()","()((()))","()()(())","(((())))","(())()()","()(())()","(()()())","(()(()))","((())())"};
   unordered_set<string> leet_out({"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"});

   vector<string> extra;

    for(string ele:my_out){
        if(leet_out.find(ele)!=leet_out.end()){
            leet_out.erase(ele);
        }else{
            extra.push_back(ele);
        }
    }

    cout<<"Extra elements in leetcode output are:"<<endl;
    for(string ele:leet_out){
        cout<<ele<<" ";
    }

    cout<<endl<<"Extra elements in my output are:"<<endl;
    for(string ele:extra){
        cout<<ele<<" ";
    }

    return 0;
}