#include <stdio.h>
#include <stdlib.h>

void push(int);
void pop(void);
void display(void);

int main(){
	int op, x;
	while(1){
		printf("\nSTACK\n");
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.exit\n");

		printf("Enter your choice:");
		scanf("%d", &op);

		switch(op){
			case 1:
			    printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;
			case 2:
			    pop();
                break;
		    case 3:
		        display();
                break;
		    case 4:
		         exit(0);
                 break;
		    default:
		        printf("Invalid options\n");
		}
	}
}

struct node{
    int data;
    struct node *next;
    };

struct node *top=NULL;

void push(int x){
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=top;
     top=temp;
}


void pop(){
     if(top==NULL){
    printf("Stack is empty.\n");
} else {
     struct node *temp;
     temp=top;
     printf("Deleted %d element.\n",temp->data);
     top=temp->next;
     temp->next=NULL;
     free(temp);
   }
}

void display(){
    struct node *temp;
    if(top==NULL){
        printf("Stack is empty.\n");
    } else{
       printf("Stack elements are: ");
       temp=top;
       while(temp!=NULL){
        printf("%d,",temp->data);
        temp=temp->next;
       }
    }
}

