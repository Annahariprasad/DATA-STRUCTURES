#include<stdio.h>
#include<stdlib.h>

int main(){
   int a[10],i,j,n,temp;
   printf("Enter number of elements:");
   scanf("%d",&n);
   for(i=0; i<n; i++){
    printf("Enter a[%d] : ",i);
    scanf("%d",&a[i]);
   }
   printf("Before Sorting:");
   for(i=0; i<n; i++){
    printf("%d,",a[i]);
   }
  printf("\n");

   for(i=0; i<n; i++){
    for(j=0; j<n-i; j++){
        if(a[j]>a[j+1]){
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
        }
    }
   }

  printf("After Sorting : ");
  for(i=0; i<n; i++){
    printf("%d,",a[i]);
  }
}
