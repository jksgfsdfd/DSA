#include<iostream>
using namespace std;

class node{
 public:
	int data;
	node *next;

	node(int data){
		this->data=data;
		next=NULL;
	}
};

void insert(node **headptr,int data){

	if(*headptr==0){
		*headptr=new node(data);
		return;
	}else{
		node *temp=*headptr;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=new node(data);
		return;
	}
}

void print(node *head){
	while(head){
		cout<<head->data<<endl;
		head=head->next;
	}
}

int main(){
	node *head;
	cout<<head<<endl;
	(*(&head))++;
	cout<<head<<endl;
	
//	insert(&head,10);
//	cout<<head;
//	insert(&head,5);
//	insert(&head,10);
//	insert(&head,10);
//	insert(&head,5);
//	insert(&head,5);
//	print(head);
}
