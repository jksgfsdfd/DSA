#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char s[1000];
	cin.getline(s,1000);
	int space=0;
	int size=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==' '){
			space++;
		}
		size++;
	}


	cout<<s<<endl;

	int j=2*space+size;
	cout<<j<<endl;
	cout<<size<<endl;

	for(int i=size;i>=0;i--){
		if(s[i]==' '){
			s[j--]='0';
			s[j--]='2';
			s[j--]='%';
		}else{
			s[j--]=s[i];
		}
		
	}

	cout<<s<<endl;

	return 0;
}
