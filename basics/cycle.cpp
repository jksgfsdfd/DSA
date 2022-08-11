#include<unordered_map>
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


bool cycle(node * head){	
	unordered_map <node *,bool> check;
	while(head){
		if(check.count(head))
			return true;
		else{
			check[head]=true;
			head=head->next;
		}
	}
	return false;
}

void makecycle(node *head){
	node *temp=head;
	if(head==NULL){
		cout<<"Empty\n";
	}else{
		while(temp->next){
			temp=temp->next;
		}
		temp->next=head;
	}
}

int main(){
	node *head=NULL;
	insertathead(&head,1);
	insertathead(&head,2);
	insertathead(&head,3);
	insertathead(&head,4);
	insertathead(&head,5);
	
	makecycle(head);

	bool val;
	val=cycle(head);
	if(val){
		cout<<"Has a cycle"<<endl;
	}else{
		cout<<"No cycle\n";
	}
	return 0;
}
