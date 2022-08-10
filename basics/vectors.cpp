#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> index(4,0);

	index.push_back(10);

	cout<<"The size of vector is "<<index.size()<<"\n";

	cout<<"The capacity of vector is "<<index.capacity()<<"\n";
	
	cout<<"Vector elements are\n";

	for(int i=0;i<index.size();i++){
		cout<<index[i]<<"\n";
	}
}
