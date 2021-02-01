#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10

void insert(int);
void delete(void);
void display(void);
void peek(void);

int top = -1, stack[CAPACITY];

void main(){
	int op, x;
	while(1){
		printf("\nSTACK\n");
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.peek\n");
		printf("5.exit\n");

		printf("Enter your choice:");
		scanf("%d", &op);

		switch(op){
			case 1: printf("Enter element: ");
			        scanf("%d", &x);
			        insert(x);
			        break;
			case 2: delete();
			        break;
		    case 3: display();
		            break;
		    case 4: peek();
		            break;
		    case 5: exit(0);
		            break;
		    default: printf("Invalid options\n");
		}
	}
}

void insert(int x){
	if(top == CAPACITY-1){
		printf("Stack is overflow\n");
	} else {
		top++;
		stack[top] = x;
		printf("successfully %d element is inserted\n", x);
	}
}

void delete(){
	int x;
	if(top == -1){
		printf("Stack is underflow\n");
	} else {
		x = stack[top];
		top--;
		printf("%d element is deleted\n", stack[top]);
	}
}

void display(){
	int i;
	if(top == -1){
		printf("Stack is underflow.\n");
	} else {
		printf("The elements are");
		for(i=0; i<=top; i++){
			printf(" %d\t", stack[i]);
		}
	}
}

void peek(){
	if(top == -1){
		printf("Stack is underflow.\n");
	} else {
		printf("The peek element is %d", stack[top]);
	}
}

