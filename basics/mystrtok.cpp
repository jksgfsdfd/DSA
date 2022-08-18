#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

char* mystrtok(char* str,char delim){
	static char* input=NULL;
	if(str!=NULL){
		input = str;
	}


	if(input==NULL){
		return NULL;
	}

	char* token=new char[(strlen(input)+1)];
	int i=0;
	for(;input[i]!='\0';i++){
		if(input[i]==delim){
			token[i]='\0';
			input=input+i+1;
			return token;
		}else{
			token[i]=input[i];
		}
	}

	if(input[i]=='\0'){
		token[i]='\0';
		input=NULL;
		return token;
	}
}

int main(){
	char input[1000];
	cin.getline(input,1000);
	vector<string> tokens;
	char* token=mystrtok(input,' ');
	tokens.push_back(token);	
	while(token=mystrtok(NULL,' ')){
		tokens.push_back(token);
	}

	for(string s:tokens){
		cout<<s<<endl;
	}
	return 0;
}
