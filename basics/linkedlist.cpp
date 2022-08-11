#include<iostream>

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

	if(*headptr==NULL){
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

void insertathead(node **headptr,int data){
	if(*headptr==NULL){
		*headptr=new node(data);
		return;
	}else{
		node *temp=new node(data);
		temp->next=*headptr;
		*headptr=temp;
		return;
	}
}


