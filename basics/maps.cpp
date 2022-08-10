#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	map<string,int> price;
	price["bmw"]=100;
	price["nexon"]=200;

	string car;
	cin>>car;
	
	if(price.count(car)){
		cout<<price[car]<<endl;
	}else{
		cout<<"car not available"<<endl;
		for(pair<string,int> avai:price){
			cout<<avai.first<<" - " <<avai.second<<endl;		
		}
	}
	return 0;
}
