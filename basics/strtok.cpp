#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main(){
	char input[1000];
	cin.getline(input,1000);

	vector<string> tokens;
	char* token=strtok(input," ");
	tokens.push_back(token);	
	while(token=strtok(NULL," ")){
		tokens.push_back(token);
	}

	for(string s:tokens){
		cout<<s<<endl;
	}
}
