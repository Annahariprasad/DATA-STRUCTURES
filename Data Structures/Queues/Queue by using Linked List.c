#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
void dequeue(void);
void traverse(void);

int main(){
	while(1){
		int op, x;
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
	    printf("3.Traverse\n");
	    printf("4.Exit\n");
	    printf("Enter your option:");
	    scanf("%d",&op);
	    switch(op){
	    	case 1:
	    		printf("Enter element:");
	            scanf("%d",&x);
	    		enqueue(x);
	    		break;
	    	case 2:
	    		dequeue();
	    		break;
	    	case 3:
	    		traverse();
	    		break;
	    	case 4:
	    		exit(0);
	    		break;
	    	default:
	    		printf("Invalid option\n");
		}
	}
}

struct node{
	int data;
	struct node *next;
};

struct node *front=0, *rear=0;

void enqueue(int x){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=x;
	newNode->next=0;
	if(front==0 && rear==0){
		front=rear=newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
		printf("Successfully inserted %d element\n",x);
	}
}

void dequeue(){
	if(front==rear){
		printf("Queue is empty\n");
	} else {
		struct node *temp;
		temp = front;
		front = temp->next;
		printf("Successfully deleted %d element\n",temp->data);
		free(temp);
	}
}

void traverse(){
	if(front==0 && rear==0){
		printf("Queue is empty\n");
	} else {
		struct node *temp;
		temp = front;
		printf("Queue elements are : ");
		while(temp!=0){
			printf("%d,",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
