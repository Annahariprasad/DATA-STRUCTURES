#include<stdio.h>
#include<stdlib.h>

void append(int);
void insertAtBegin(int);
void insertAtPosition(int);
void delete(void);
int length(void);
void display(void);

int main(){
    int op,x,len;
while(1){
 printf(" 1.Append\n 2.InsertAtBegin\n 3.insertAtPosition\n 4.Delete\n 5.Length\n 6.Display\n 7.Exit\n");
 printf("Enter your option:");
 scanf("%d",&op);
 switch(op){
case 1:
    printf("Enter element : ");
    scanf("%d",&x);
    append(x);
    break;
case 2:
    printf("Enter element : ");
    scanf("%d",&x);
    insertAtBegin(x);
    break;
case 3:
    printf("Enter element : ");
    scanf("%d",&x);
    insertAtPosition(x);
    break;
case 4:
    delete();
    break;
case 5:
    len=length();
    printf("Double Circular List size is %d.\n",len);
    break;
case 6:
    display();
    break;
case 7:
    exit(0);
    break;
default:
    printf("Invalid option\n");
 }
 }
}

struct node{
 int data;
 struct node *prev;
 struct node *next;
};

typedef struct node node;

node *head=NULL;

int createNode(node *n,int x){
   n=(node*)malloc(sizeof(node));
   n->data=x;
   n->prev=NULL;
   n->next=head;
   return n;
}

void append(int x){
  int n;
  node *newNode=createNode(n,x);
  if(head==NULL){
    newNode->next=newNode;
    head=newNode;
    printf("Successfully %d element is Inserted at end\n",x);
  } else {
   node *p=head;
   while(p->next!=head){
    p=p->next;
   }
   p->next=newNode;
   newNode->prev=p;
   newNode->next=head;
   printf("Successfully %d element is Inserted at end\n",x);
  }
}

void insertAtBegin(int x){
  int n;
  node *newNode=createNode(n,x);
  if(head==NULL){
    newNode->next=newNode;
    head=newNode;
  } else {
   node *p=head;
   while(p->next!=head){
    p=p->next;
   }
   p->next=newNode;
   newNode->next=head;
   head=newNode;
   printf("Successfully %d element is inserted at Begin\n",x);
  }
}

void insertAtPosition(int x){
 int n,len=length(),loc;
 node *newNode=createNode(n,x);
 printf("Enter position : ");
 scanf("%d",&loc);
 if(loc>len){
    printf("Circular Double Linked List size is %d\n",len);
 } else if(head==NULL){
    newNode->next=newNode;
    head=newNode;
 } else if(loc==1){
     insertAtBegin(x);
 } else {
   int i=1;
   node *p=head;
   while(i<loc-1){
    p=p->next;
    i++;
   }
   newNode->next=p->next;
   p->next->prev=newNode;
   p->next=newNode;
   newNode->prev=p;
   printf("Successfully %d element is inserted at %d position\n",x,loc);
 }
}

void delete(){
 node *p=head,*q=head;
 int loc,len=length();
 printf("Enter position : ");
 scanf("%d",&loc);
 if(loc>len){
    printf("Circular Linked List size is %d.\n",len);
 } else if(head==NULL){
    printf("List is empty.\n");
 } else if(loc==1){
   while(p->next!=head){
    p=p->next;
   }
   p->next=head->next;
   head=q->next;
   q->next=NULL;
   free(q);
   printf("Successfully Deleted 1st element.\n");
 } else {
   int i=1;
   while(i<loc-1){
    p=p->next;
    i++;
   }
   q=p->next;
   p->next=q->next;
   q->next->prev=p;
   q->prev=NULL;
   q->next=NULL;
   free(q);
   printf("Successfully deleted %d position.\n",loc);
 }
}

int length(){
 int count=0;
 node *p=head;
 if(head==NULL){
    printf("List is empty.\n");
 } else{
 do{
    count++;
    p=p->next;
 }while(p!=head);
 }
 return count;
}

void display(){
 node *p=head;
 if(head==NULL){
    printf("List is empty.\n");
 } else {
     printf("Circular Double Linked List elements are : ");
   do{
    printf("%d-->",p->data);
    p=p->next;
   } while(p!=head);
   printf("%d\n",p->data);
 }
}

