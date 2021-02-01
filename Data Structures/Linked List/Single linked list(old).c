#include<stdio.h>
#include<stdlib.h>

void append(void);
void insertAtBegin(void);
void addAfter(void);
int  length(void);
void display(void);
void delete(void);

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;

void append() {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data for a node:");
	scanf("%d", &temp->data);
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
	} else {
		struct node *p;
		p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

int length() {
	struct node *temp;
	int count = 0;
	temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void display() {
	struct node *temp;
	temp = head;
	if(temp == NULL){
		printf("List is empty.\n");
	} else {
		while(temp != NULL) {
			printf("%d-->", temp->data);
			temp = temp->next;
		}
	}
}

void insertAtBegin(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data for a node: ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
	} else {
		temp->next = head;
		head = temp;
	}
}

void addAfter() {
	struct node *temp, *temp1;
	int loc, len, i = 1;
	printf("Enter location : ");
	scanf("%d", &loc);
	len = length();
	if(loc>len) {
		printf("Invalid location");
	} else {
		temp = head;
		while(i<loc){
			temp = temp->next;
			i++;
		}
		temp1 = (struct node*)malloc(sizeof(struct node));
		printf("Enter data for a node: ");
		scanf("%d", &temp1->data);
		temp1->next = NULL;
		temp1->next = temp->next;
		temp->next = temp1; 
 } 
}

void delete() {
	struct node *temp, *temp1;
	int loc, len, i = 1;
	printf("Enter location: ");
	scanf("%d", &loc);
	len = length();
	if(loc>len){
		printf("Invalid Location\n");
	} else if(loc == 1){
		temp = head;
		head = temp->next;
		temp->next = NULL;
		free(temp);
	} else {
		temp = head;
		while(i<loc-1){
			temp=temp->next;
			i++;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		temp1->next = NULL;
		free(temp1);
	}
}
void main() {
	int op, len;
	while(1) {
		printf("\nSingly linked list\n");
		printf("1.Append\n");
		printf("2.Insertatbegin\n");
		printf("3.addafter\n");
		printf("4.length\n");
		printf("5.display\n");
		printf("6.delete\n");
		printf("7.exit\n");
		
		printf("Enter your option:");
		scanf("%d", &op);
		switch(op) {
			case 1: append();
			        break;
			case 2: insertAtBegin();
			        break;
		    case 3: addAfter();
		            break;
		    case 4: len = length();
			        printf("Length of the list is %d", len);
		            break;
		    case 5: display();
		            break;
		    case 6: delete();
		            break;
		    case 7: exit(1);
		    default: printf("Invalid option");
		}
	}
}
