#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
	string s("hello make tokens");
	stringstream ss(s);
	vector<string> tokens;
	string token;
	while(getline(ss,token,' ')){
		tokens.push_back(token);
	}
	for(string token:tokens){
		cout<<token<<endl;
	}
}
