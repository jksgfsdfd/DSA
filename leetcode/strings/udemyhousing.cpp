#include<iostream>
using namespace std;

void findseq(int *arr,int n,int key){
	int i=0;
	int j=0;
	int sum=arr[0];
	while(j<n){
		if(sum==key){
			cout<<i<<" to "<<j<<endl;
			if(i==j){
				j++;
				if(j==n)
					return;
				sum=sum+arr[j];
			}else{
				sum=sum-arr[i];
				i++;
			}
		}else if(sum>key){
			if(i==j){
				j++;
				if(j==n)
					return;
				sum=sum+arr[j];
			}else{
				sum=sum-arr[i];
				i++;
			}
		}else{		
				j++;
				if(j==n)
					return;
				sum=sum+arr[j];
		}

	}
}

int main(){
	int plots[]={1,3,2,1,4,1,3,2,1,1};
	int n=sizeof(plots)/sizeof(*plots);
	int k=8;
	findseq(plots,n,k);
}
