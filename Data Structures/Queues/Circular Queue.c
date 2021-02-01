#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void insert(int);
void delete(void);
void display(void);

int main() {
	while(1){
		int op,x;
		printf("\"Circular Queue\"\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your option:");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter element:");
				scanf("%d",&x);
				insert(x);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid option.\n");
		}
	}
}

int front = -1, rear = -1, cqueue[SIZE];

void insert(int x){
	if(front==-1 && rear==-1){
		front=0;
		rear=0;
		cqueue[rear]=x;
		printf("Successfully Inserted %d element.\n",x);
	} else if((rear+1)%SIZE==front){
		printf("Circular Queue is full.\n");
	} else {
		rear=(rear+1)%SIZE;
		cqueue[rear]=x;
		printf("Successfully Inserted %d element.\n",x);
	}
}

void delete(){
	if(front==-1 && rear==-1){
		printf("Circular Queue is empty.\n");
	} else if(front==rear){
		front=-1;
		rear=-1;
	} else {
		printf("%d",cqueue[front]);
		front=(front+1)%SIZE;
	}
}

void display(){
	int i=front;
	if(front==-1 && rear==-1){
		printf("Circular Queue is empty.\n");
	} else {
		printf("Circular Queue elements are: ");
		while(i!=rear){
			printf("%d, ",cqueue[i]);
			i=(i+1)%SIZE;
		}
		printf("%d\n",cqueue[rear]);
	}

}
