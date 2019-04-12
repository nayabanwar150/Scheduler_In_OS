/*
Name = Mohd Nayab Anwar
Reg No = 11703167
*/



#include<stdio.h>
#include<conio.h>
void main()
{
 int TS,pid[10],need[10],WT[10],TAT[10],i,j,n,n1;
 int BT[10],flag[10],TTAT=0,TWT=0;
 float AWT,ATAT;
printf("\t ROUND ROBIN SCHEDULING); 
printf("Enter the number of Processors \n");
 scanf("%d",&n);
 n1=n;
 printf("\n Enter the Timeslice \n");
 scanf("%d",&TS);
 for(i=1;i<=n;i++)
{
printf("\n Enter the process ID %d",i);
scanf("%d",&pid[i]);
printf("\n Enter the Burst Time for the process");
scanf("%d",&BT[i]);
need[i]=BT[i];
}
for(i=1;i<=n;i++)
{
  flag[i]=1;
  WT[i]=0;
 }
while(n!=0)
 {
   for(i=1;i<=n;i++)
   {
     if(need[i]>=TS)
     {
	 for(j=1;j<=n;j++)
       {
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  WT[j]+=TS;
       }
 need[i]-=TS;
 if(need[i]==0)
{
flag[i]=0;
n--;
}
}
else
{
  for(j=1;j<=n;j++)
      {
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  WT[j]+=need[i];
       }
need[i]=0;
n--;
flag[i]=0;
}
 }
}
for(i=1;i<=n1;i++)
{
TAT[i]=WT[i]+BT[i];
TWT=TWT+WT[i];
TTAT=TTAT+TAT[i];
}
AWT=(float)TWT/n1;
ATAT=(float)TTAT/n1;
printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");
printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
for(i=1;i<=n1;i++)
{
printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],BT[i],WT[i],TAT[i]);
}
printf("\n The average Waiting Time=4.2f",AWT);
printf("\n The average Turn around Time=4.2f",ATAT);
getch();
}         

