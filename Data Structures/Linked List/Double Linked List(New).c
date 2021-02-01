#include<stdio.h>
#include<stdlib.h>

void append();
void addAtBegin();
void addAfter();
void delete();
void display();
int length();
void reverseList();

int main(){
 while(1){
  int op,x;
  printf("\nDouble Linked List\n");
  printf("1.Append.\n");
  printf("2.AddAtBegin.\n");
  printf("3.AddAfter.\n");
  printf("4.Delete.\n");
  printf("5.Display.\n");
  printf("6.Length.\n");
  printf("7.Reverse the list.\n");
  printf("8.Exit.\n");
  printf("Enter your option: ");
  scanf("%d",&op);
  switch(op){
   case 1:
       printf("Enter element: ");
       scanf("%d",&x);
       append(x);
       break;
   case 2:
       printf("Enter element: ");
       scanf("%d",&x);
       addAtBegin(x);
       break;
   case 3:
       printf("Enter element: ");
       scanf("%d",&x);
       addAfter(x);
      break;
   case 4:
      delete();
      break;
   case 5:
      display();
      break;
   case 6:
      printf("Length is %d\n", length());
      break;
   case 7:
      reverseList();
	  break;    
   case 8:
    exit(0);
    break;
   default:
    printf("Invalid option.\n");
    }
  }
}

struct node{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head=NULL;

void append(int x){
  struct node *newNode;
  newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=x;
  newNode->prev=NULL;
  newNode->next=NULL;
  if(head==NULL){
    head=newNode;
    printf("Successfully inserted.\n");
  } else {
      struct node *p;
      p=head;
      while(p->next!=NULL){
        p=p->next;
      }
      p->next=newNode;
      printf("Successfully inserted.\n");
  }
}

void addAtBegin(int x){
  struct node *newNode;
  newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=x;
  newNode->prev=NULL;
  newNode->next=NULL;
  if(head==NULL){
    head=newNode;
    printf("Successfully inserted.\n");
  } else {
    newNode->next=head;
    head=newNode;
    printf("Successfully inserted.\n");
 }
}

void addAfter(int x){
 struct node *newNode;
 int loc,len,i=1;
 len=length();
 newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=x;
 newNode->prev=NULL;
 newNode->next=NULL;
 printf("Enter location: ");
 scanf("%d",&loc);
 if(loc>len){
    printf("Linked List having %d nodes.\n",len);
 } else {
    struct node *p;
    p=head;
    while(i<loc){
      p=p->next;
      i++;
    }
    newNode->next=p->next;
    p->next->prev=newNode;
    newNode->prev=p;
    p->next=newNode;
    printf("Successfully inserted.\n");
 }
 }

 void delete(){
  struct node *p,*q;
  int loc, len, i=1;
  len=length();
  printf("Enter your location: ");
  scanf("%d",&loc);
  if(loc>len){
    printf("Linked list having %d nodes.\n",len);
  } else if(head==NULL){
    printf("Linked list is empty.\n");
  } else if(loc==1){
    p=head;
    head=p->next;
    head->prev=NULL;
    p->prev=p->next=NULL;
    free(p);
    printf("Successfully deleted.\n");
  } else {
    p=head;
    while(i<loc-1){
        p=p->next;
        i++;
    }
    q=p->next;
    p->next=q->next;
    p->prev=p;
    q->prev=q->next=NULL;
    free(q);
    printf("Successfully deleted.\n");
  }
 }
 
 void reverseList(){
  struct node *p,*q;
  int len,i,j,k,temp;
  len=length();
  j=len-1;
  p=q=head;
  for(i=0; i<j; i++){
    for(k=0; k<j; k++){
        q=q->next;
    }
    temp=p->data;
    p->data=q->data;
    q->data=temp;
    j--;
    p=p->next;
    q=head;
  }
}

 int length(){
   struct node *p;
   int count=0;
   if(head==NULL){
    printf("Linked List is empty.\n");
   } else {
    p=head;
   while(p!=NULL){
    p=p->next;
    count++;
   }}
   return count;
 }

 void display(){
   struct node *p;
   p=head;
   if(head==NULL){
    printf("Linked list is empty.\n");
   } else {
    printf("Double Linked list elements:");
    while(p!=NULL){
        printf("%d-->",p->data);
        p=p->next;
    }
    printf("\n");
   }
 }
