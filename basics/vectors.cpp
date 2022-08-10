#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	vector<int> index(4);

	vector<string> arr(4);
	arr[0]="hello";
	cout<<"The size of vector is "<<index.size()<<"\n";

	cout<<"The capacity of vector is "<<index.capacity()<<"\n";
	
	cout<<"Vector elements are\n";

	for(int i=0;i<index.size();i++){
		cout<<index[i]<<"\n";
	}

	for(string x:arr){
		cout<<x<<endl;
	}
}
