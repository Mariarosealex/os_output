#include<stdio.h>
void main()
{
  printf("Enter the number of processes\n");
  int num;
  scanf("%d",&num);
  int p[num];
  int bt[num],wt[num],tat[num];
  int tot_wt=0,tot_tat;
  printf("Enter the process names and burst times of each process\n");
  for(int i=0;i<num;i++)
   {
     scanf("%d",&p[i]);
     scanf("%d",&bt[i]);
   }
   int temp,shift;
   for(int i=0;i<num;i++)
   {
     for(int j=0;j<i;j++)
     {
       if(bt[i]<bt[j]){
       temp=bt[i];
       bt[i]=bt[j];
       bt[j]=temp;
       shift=p[i];
       p[i]=p[j];
       p[j]=shift;
       }                       
     }
   }
   wt[0]=0;
   tat[0]=bt[0];
   tot_tat=tat[0];
   printf("Process name: %d\n Process burst time: %d\nProcess waiting time: %d\nProcess turn around time :%d\n",p[0],bt[0],wt[0],tat[0]);
   for(int i=1;i<num;i++)
   {  
     wt[i]=wt[i-1]+bt[i-1];
     tot_wt=tot_wt+wt[i];
     tat[i]=tat[i-1]+bt[i];
     tot_tat=tot_tat+tat[i];
     printf("Process name: %d\n Process burst time: %d\nProcess waiting time: %d\nProcess turn around time :%d\n",p[i],bt[i],wt[i],tat[i]);
   } 
   printf("Total waiting time: %d\nTotal turn around time :%d\n",tot_wt,tot_tat);
   float av_wt,av_tat;
   av_wt=(float)tot_wt/num;
   av_tat=(float)tot_tat/num;
  printf("Average waiting time: %f\nAverage turn around time : %f",av_wt,av_tat);
}  
