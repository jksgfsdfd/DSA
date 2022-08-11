#include<stdio.h>
typedef struct node node;

struct node{
	int data;
	node *next;
};

int main(){
	node *head;
	printf("%p\n",head);
	(*(&head))++;
	printf("%p\n",head);
}
