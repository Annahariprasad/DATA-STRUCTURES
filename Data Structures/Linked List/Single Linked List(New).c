 #include<stdio.h>
#include<stdlib.h>

void append(int);
void addAfter(int);
void addAtBegin(int);
void delete(void);
void display(void);
int length(void);
void reverseList(void);
void middleList(void);

int main(){
    while(1){
    int op, x;
    printf("Single Linked List\n");
    printf("1.Append\n");
    printf("2.Addafter\n");
    printf("3.AddatBegin\n");
    printf("4.Delete\n");
    printf("5.Display\n");
    printf("6.Length\n");
    printf("7.Reverse List\n");
    printf("8.Middle element of  the list\n");
    printf("9.Exit\n");
    printf("Enter your option:");
    scanf("%d",&op);
    switch(op){
       case 1:
          printf("Enter element:");
          scanf("%d",&x);
          append(x);
          break;
       case 2:
           printf("Enter element:");
           scanf("%d",&x);
           addAfter(x);
           break;
       case 3:
           printf("Enter element:");
           scanf("%d",&x);
           addAtBegin(x);
           break;
       case 4:
           delete();
           break;
       case 5:
            display();
            break;
       case 6:
            length();
            break;
       case 7:
            reverseList();
            break;
       case 8:
            middleList();
       case 9:
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

struct node *head = NULL;

void append(int x){
   struct node *newNode;
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=x;
   newNode->next=NULL;
   if(head == NULL){
        head = newNode;
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

int length(){
   struct node *p;
   int count=0;
   if(head==NULL){
    printf("Linked list is empty.\n");
   } else {
   p=head;
   while(p!=NULL){
    p=p->next;
    count++;
   }
   return count;
}}

void addAtBegin(int x){
   struct node *newNode;
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=x;
   newNode->next=NULL;
   if(head==NULL){
    head=newNode;
   } else {
     newNode->next=head;
     head=newNode;
     printf("Successsfully inserted %d element.\n",x);
   }
}

void addAfter(int x){
   struct node *newNode;
   int loc,len,i=1;
   len=length();
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=x;
   newNode->next=NULL;
   printf("Enter your location:");
   scanf("%d",&loc);
   if(loc>len){
    printf("Linked list having %d nodes.\n",len);
   } else {
     struct node *p;
     p=head;
     while(i<loc-1){
        p=p->next;
        i++;
     }
     newNode->next=p->next;
     p->next=newNode;
   }
}

void delete(){
   struct node *p,*q;
   int loc,len,i=1;
   len=length();
   printf("Enter your location:");
   scanf("%d",&loc);
   if(head==NULL){
    printf("Linked List is empty.\n");
   }else if(loc>len){
    printf("Linked list having %d nodes.\n",len);
   } else if(loc==1){
        p=head;
        head=p->next;
        p->next=NULL;
        free(p);
     } else {
       p=head;
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

void middleList(){
  int count;
  struct node *p;
  p=head;
  count=length();
  int i=0;
  int len = count/2;
  while(i<len){
    p=p->next;
  }
  printf("Middle element is %d", p->data);
}

void display(){
   struct node *p;
   p=head;
   if(head==NULL){
    printf("Linked list is empty.\n");
   } else {
    printf("Linked elements are: ");
    while(p!=NULL){
        printf("%d-->",p->data);
        p=p->next;
    }
    printf("\n");
   }
}
