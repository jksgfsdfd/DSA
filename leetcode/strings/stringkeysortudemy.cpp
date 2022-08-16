#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<pair<string,string>> makekeymap(vector<string> arr,int key){
	vector<pair<string,string>> vp;
	char * p;
	for(string s:arr){
		pair<string,string> a;
		a.first=s;
		p=strtok((char *)s.c_str()," ");
		for(int i=0;i<key-1;i++){
			p=strtok(NULL," ");
		}
		a.second=(string) p;
		vp.push_back(a);
	}
	return vp;
}

int convertToInt(string s){
	int num=0;
	for(int i=0;i<s.length();i++){
		num=num*10+(s[i]-'0');
	}
	return num;
}

bool numericCompare(pair<string,string> s1,pair<string,string> s2){
	string key1,key2;
	key1=s1.second;
	key2=s2.second;
	
	return convertToInt(key1) < convertToInt(key2);
}

bool lexicalCompare(pair<string,string> s1,pair<string,string> s2){
	return (s1.second)<(s2.second);
}

int main(){
	int count;
	cin>>count;
	cin.get();
	vector<string> arr;
	string temp;
	while(count){
		getline(cin,temp);
		arr.push_back(temp);
		count--;
	}

	int key;
	string type;
	string reverse;
	cin>>key>>type>>reverse;
	vector<pair<string,string>> vp;
	vp=makekeymap(arr,key);
	
	if(type=="numeric"){
		sort(vp.begin(),vp.end(),numericCompare);
	}else{
		sort(vp.begin(),vp.end(),lexicalCompare);
	}
	if(reverse=="reverse"){
		int left=0;
		int right=vp.size()-1;
		pair<string,string> temp;
		while(left<right){
			temp=vp[right];
			vp[right]=vp[left];
			vp[left]=temp;
			left++;
			right--;
		}
	}
	for(pair<string,string> x:vp){
		cout<<x.first<<endl;
	}
}
