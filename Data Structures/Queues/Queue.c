#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void enqueue(int);
void dequeue(void);
void traverse(void);
void peek(void);

int main(){
	while(1){
		int op, x;
		printf("\n1.Insert an element into a queue\n");
		printf("2.Delete an element from the queue\n");
		printf("3.Transverse the elements of the queue\n");
		printf("4.Peek of the element.\n");
		printf("5.Exit\n");
		printf("Enter your option:");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter the element:");
				scanf("%d", &x);
				enqueue(x);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				traverse();
				break;
            case 4:
                peek();
                break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nInvalid option\n");
		}
	}
}

int front = 0, rear = 0;
int queue[SIZE];

void enqueue(int x){
	if(rear==SIZE-1){
		printf("\nQueue is full\n");
	} else{
   		queue[rear]=x;
        rear++;
        printf("\nSuccessfully %d element is inserted\n", x);
 	}
}

void dequeue(){
	int i;
	if(front==rear){
		printf("\nQueue is empty\n");
	} else{
		printf("\nDeleted %d element\n",queue[front]);
		for(i=0; i<=rear; i++){
			queue[i]=queue[i+1];
		}
		rear--;
	}
}

void traverse(){
	int i;
	if(front==rear){
		printf("\nQueue is empty\n");
	} else {
		printf("\nQueue Elements are : ");
		for(i=front; i<rear; i++){
			printf("%d,",queue[i]);
		}
		printf("\n");
	}
}

void peek(){
  if(front==rear){
    printf("Queue is empty.\n");
  } else {
    printf("Peek element is %d",queue[rear]);
     }
}
