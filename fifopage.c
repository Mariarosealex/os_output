#include<stdio.h>
void main(){
int j=0,pgfault=0,limit;
printf("Enter the limit");
scanf("%d",&limit);
int pg[limit],frame[3]={-1,-1,-1};
printf("Enter the reference string:");
for(int i=0;i<limit;i++){
scanf("%d",&pg[i]);
}
printf("Reference_String|frame\n");
for(int i=0;i<limit;i++){
printf("        %d      |",pg[i]);
int available=0;
for(int k=0;k<3;k++){
if(frame[k]==pg[i]){
available=1;
break;
}
}
if(available==0){
frame[j]=pg[i];
j=(j+1)%3;
pgfault++;
}
for(int k=0;k<3;k++)
printf("%d ",frame[k]);
printf("\n");
}
printf("Page fault=%d\n",pgfault);
}

