#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string s("find occurences of word,hello word next word previos word");
	int index;
	string word="word";
	index=s.find(word);
	int count=0;
	while(index!=-1){
		cout<<word<<" found at index"<<index<<endl;
		count++;
		index=s.find(word,index+1);
	}
	cout<<"TOtal "<<count<<" are present"<<endl;
	return 0;
}


