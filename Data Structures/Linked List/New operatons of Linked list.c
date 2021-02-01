#include<stdio.h>
#include<stdlib.h>

void append(int);
void display();
void reverse();
void middle();
void endEle();
void pelement();
void search();
int length();

int main(){
   int op, x, len;
   while(1){
   printf(" 1.Append\n 2.Display\n 3.Reverse\n 4.Middle\n 5.Endelement\n 6.P(element)\n 7.Search\n 8.Length\n 9.Exit\n");
   printf("Enter your option: ");
   scanf("%d",&op);
   switch(op){
case 1:
    printf("Enter element: ");
    scanf("%d",&x);
    append(x);
    break;
case 2:
    display();
    break;
case 3:
    reverse();
    break;
case 4:
    middle();
    break;
case 5:
   endEle();
   break;
case 6:
    pelement();
    break;
case 7:
    search();
    break;
case 8:
    len=length();
    printf("Length of the list : %d\n",len);
    break;
case 9:
    exit(0);
    break;
default:
    printf("Invalid option\n");
} } }

struct node {
 int data;
 struct node *next;
};

struct node *head=NULL;

void append(int x){
 struct node *newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=x;
 newNode->next=NULL;
 if(head==NULL){
    head=newNode;
 } else {
     struct node *p;
     p=head;
     while(p->next!=NULL){
        p=p->next;
     }
     p->next=newNode;
     printf("Successfully inserted %d element.\n",x);

 }
}

void display(){
  struct node *p;
  p=head;
  if(head==NULL){
    printf("Linked list is empty.\n");
  } else{
      printf("Linked list elements are : ");
    while(p!=NULL){
    printf("%d-->",p->data);
    p=p->next;
    }
    printf("\n");
  }
}

int length(){
  struct node *p=head;
  int count=0;
  if(head==NULL){
    printf("Linked list is empty.\n");
  } else {
   while(p!=NULL){
    count++;
    p=p->next;
   }
  }
  return count;
}

void reverse(){
 struct node *p=head,*q=head;
 int i,j=length()-1,k;
 if(head==NULL){
    printf("Linked list is empty.\n");
 } else {
  for(i=0; i<j; i++){
    for(k=0; k<j; k++){
        q=q->next;
    }
    int temp=p->data;
    p->data=q->data;
    q->data=temp;
    j--;
    p=p->next;
    q=head;
  }}}

void middle(){
 struct node *p=head;
 int len=length(), mid=len/2;
 if(len%2!=0){
 for(int i=0; i<mid; i++){
    p=p->next;
 }
 printf("Middle element :%d\n", p->data);
} else {
   for(int i=0; i<mid-1; i++){
    p=p->next;
   }
   printf("Middle elements are %d, %d\n",p->data,p->next->data);
}}

void endEle(){
 struct node *p=head;
 int len=length(),n,m;
 printf("Enter position :");
 scanf("%d",&n);
  m=len-n+1;
 if(head==NULL){
     printf("Linked list is empty.\n");
 } else if(n>len){
     printf("Linked list size is %d\n",len);
 } else {
  int i=1;
  while(i<m){
    p=p->next;
    i++;
 }
 printf("Position Element is %d from end\n",p->data);
}
}

void pelement(){
 struct node *p=head;
 int n,len=length();
 printf("Enter position:");
 scanf("%d",&n);
 if(n>len){
    printf("Linked list size is %d\n",len);
 } else if(head==NULL){
     printf("Linked list is empty.\n");
 } else {
     for(int i=1; i<n; i++){
        p=p->next;
     }
     printf("Position of the element is %d\n",p->data);
 }
}

void search(){
 struct node *p=head;
 int n, count=1;
 printf("Enter number:");
 scanf("%d",&n);
 if(head==NULL){
    printf("Linked list is empty.\n");
 } else {
     while(p!=NULL){
            if(p->data==n){
                printf("Element %d in %d position.\n",n,count);
                break;
     } else if( p->data!=n){
         count++;
         p=p->next;
}
}
}}
