#include<stdio.h>
#include<stdlib.h>

void append(int);
void addAtBegin(int);
void insertAtPosition(int);
void delAtBegin(void);
void pDelete(void);
int length(void);
void display(void);

int main(){
   int op, x, len;
while(1){
   printf(" 1.Append\n 2.AddAtBegin\n 3.InsertAtPosition\n 4.DelAtbegin\n 5.pDelete\n 6.Length\n 7.Display\n 8.Exit\n");
   printf("Enter your option: ");
   scanf("%d", &op);
   switch(op){
case 1:
    printf("Enter elements : ");
    scanf("%d",&x);
    append(x);
    break;
case 2:
    printf("Enter elements : ");
    scanf("%d",&x);
    addAtBegin(x);
    break;
case 3:
    printf("Enter elements : ");
    scanf("%d",&x);
    insertAtPosition(x);
    break;
case 4:
    delAtBegin();
    break;
case 5:
    pDelete();
    break;
case 6:
    len=length();
    printf("Circular List Length is %d\n",len);
    break;
case 7:
    display();
    break;
case 8:
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

struct node *head=NULL;

void append(int x){
   struct node *newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=x;
   newNode->next=head;
   if(head==NULL){
    newNode->next=newNode;
    head=newNode;
   } else {
     struct node *p=head;
     while(p->next!=head){
        p=p->next;
     }
     p->next=newNode;
     printf("Successfully inserted %d element.\n",x);
   }
}

void addAtBegin(int x){
  struct node *newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=x;
  newNode->next=head;
  if(head==NULL){
    newNode->next=newNode;
    head=newNode;
  } else {
    struct node *p=head;
    newNode->next=p;
    head=newNode;
    while(p->next!=newNode->next){
        p=p->next;
    }
    p->next=head;
  }
}

void insertAtPosition(int x){
   struct node *newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=x;
   newNode->next=head;
   int len=length(),loc;
   printf("Enter location: ");
   scanf("%d",&loc);
   if(loc>len){
    printf("Circular List Length is %d\n",len);
   } else if(loc==1){
    struct node *p=head;
    newNode->next=p;
    head=newNode;
    while(p->next!=newNode->next){
        p=p->next;
    }
    p->next=head;
    printf("Successfully %d element is inserted in %d position\n",x,loc);
   } else {
    struct node *p=head;
    int i=1;
    while(i<loc-1){
        p=p->next;
        i++;
    }
    newNode->next=p->next;
    p->next=newNode;
    printf("Successfully %d element is inserted in %d position\n",x,loc);
   }
}

void delAtBegin(){
   struct node *p=head, *q=head;
   if(head==NULL){
    printf("Circular Linked List is empty.\n");
   } else {
     while(p->next!=head){
        p=p->next;
     }
     p->next=head->next;
     head=q->next;
     q->next=NULL;
     free(q);
     printf("Successfully deleted.\n");
   }
}

void pDelete(){
 struct node *p=head, *q;
 int len=length(),loc;
 printf("Enter location : ");
 scanf("%d",&loc);
 if(head==NULL){
    printf("Circular List is empty.\n");
 } else if(loc>len){
    printf("Circular List size is %d\n",len);
 } else if(loc==1){
   delAtBegin();
 } else {
  int i=1;
  while(i<loc-1){
    p=p->next;
    i++;
  }
  q=p->next;
  p->next=q->next;
  q->next=NULL;
  free(q);
 }
}

int length(){
 struct node *p=head;
 int count=0;
 if(head==NULL){
    printf("Circular List is empty.\n");
 } else {
   do{
    count++;
    p=p->next;
   }while(p!=head);
  }
  return count;
}

void display(){
   struct node *p=head;
   if(head==NULL){
    printf("Circular List is empty.\n");
   } else {
       printf("Circular List elemenst are: ");
       do{
        printf("%d-->",p->data);
        p=p->next;
       }
    while(p!=head);
    printf("%d",p->data);
   }
   printf("\n");
}

