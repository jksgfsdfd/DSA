#include<stdio.h>

int main(){
	int num;
//	int *pointer;
	(*(&num))++;
	printf("%d",num);
}
