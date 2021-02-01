#include<stdio.h>
#include<stdlib.h>

void append(void);
void insertAtBegin(void);
void addAfter(void);
int length(void);
void display(void);
void delete(void);

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *head = NULL;

void main() {
	int op, len;
	while(1){
		printf("\nDouble Linked List\n");
		printf("1.Append\n");
		printf("2.InsertAtBegin\n");
		printf("3.addAfter\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Exit\n");
		
		printf("Enter your option:");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				append();
				break;
			case 2:
				insertAtBegin();
				break;
			case 3:
				addAfter();
				break;
			case 4:
				len = length();
				printf("The length of the list is %d", len);
				break;
		    case 5:
		    	display();
		    	break;
		    case 6:
		    	delete();
		    	break;
		    case 7:
		    	exit(1);
		    	break;
		    default: printf("Invalid option\n");
		}
	}
}

void append(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d", &temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(head == NULL){
		head = temp;
	} else {
		struct node *p;
		p = head;
		while(p->right != NULL){
			p = p->right;
		}
		p->right = temp;
	}
}

void insertAtBegin(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d", &temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(head == NULL){
		head = temp;
	} else {
		temp->right = head;
		head->left = temp;
		head = temp;
	}
}

void addAfter(){
	struct node *temp, *p;
	int loc, len, i = 1;
	printf("Enter location:");
	scanf("%d", &loc);
	len = length();
	if(loc>len){
		printf("Invalid location\n");
		printf("The list having %d nodes\n", len);
	} else {
		p = head;
		while(i<loc){
			p = p->right;
			i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d", &temp->data);
		temp->left = NULL;
		temp->right = NULL;
		temp->right = p->right;
		p->right->left = temp;
		p->right = temp;
		temp->left = p;
	}
}

int length(){
	struct node *temp;
	int count=0;
	temp = head;
	while(temp != NULL){
		temp = temp->right;
		count++;
	}
	return count;
}

void display(){
	struct node *temp;
	temp = head;
	if(head == NULL){
		printf("List is empty.\n");
	} else {
		while(temp != NULL){
			printf("%d-->", temp->data);
			temp = temp->right;
		}
	}
}

void delete(){
	struct node *temp, *p;
	int loc, len, i = 1;
		printf("Enter location:");
		scanf("%d", &loc);
		len = length();
		if(loc>len){
			printf("Invalid location.\n");
			printf("The list haing %d nodes.\n", len);
		} else if(loc == 1){
			temp = head;
			head = temp->right;
			head->left = NULL;
			temp->right = NULL;
			free(temp);
		} else {
			temp = head;
			while(i<loc-1){
				temp = temp->right;
				i++;
			}
			p = temp->right;
			temp->right = p->right;
			p->right->left = temp;
			p->left = NULL;
			p->right = NULL;
			free(p);
		}
	}



