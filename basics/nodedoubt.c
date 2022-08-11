#include<stdio.h>
#pragma pack(1)
typedef struct node node;

struct node{
	int data;
	node *next;
};

int main(){
	node *head;
	printf("size of node is %ld\n",sizeof(node));
	printf("size of int is %ld\n",sizeof(int));
	printf("size of node * is %ld\n",sizeof(node*));
	printf("%p\n",head);
	(*(&head))++;
	printf("%p\n",head);
}
