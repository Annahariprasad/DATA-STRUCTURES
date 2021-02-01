#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;
int len;
#include "slloperations.c"

void main()
{
	int ch;
	while(1)
	{
	printf("Single linked list operations... \n\n");
	printf(" 1. Insert \n");
	printf(" 2. addatbegin \n");
	printf(" 3.  length \n");
	printf(" 4.  addatposition \n");
	printf(" 5.  display SLL \n");
	printf(" 6. reversing nodes\n");
	printf(" 7.  deletion of a node at begin, postion,ending\n");
	printf(" 8. exit \n");
	
	printf("Enter u r choice  :");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1 :  append();
		           break;
		case 2 :  addatbegin();
		           break;
		case 3 :  len = length();
		          printf("Length is %d\n",len);
		           break;
		case 4 :  addatposition();
					break;
		case 5 :   display();
					break;
	    case 6 :  reversingnodes();
					break;
		case 7 :   delete();
					break;
		case 8 :  exit(1);
		default: printf("invalid input \n");	           
	}
  }
}



