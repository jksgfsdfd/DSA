#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool lexisort(string s1,string s2){
	return s1 < s2;
}

int main(){
	vector<string> nums={"3","30","34","250"};
	sort(nums.begin(),nums.end());
	for(string s:nums){
		cout<<s<<endl;
	}
}
