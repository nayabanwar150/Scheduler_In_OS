/* ==================================
    Name : Mohd Nayab Anwar
    Section : K17PD
    Roll no : 16
    Registration no : 11703167
  ===================================
*/

// Header Files
#include<stdio.h>

int main()
{
	int i,m;
	printf("\nenter number of processes");
	scanf("%d",&m);
	int arrivalTime[m];
	int burst[m],burst1[m];
	int waiting[m];
	int tarrivalTime[m];
	int tq1 = 3;
	int tq2 = 6;
	int avgT = 0;
	int avgW = 0;
	printf("\nEnter arival time of processes:");
	for(i=0;i<m;i++)
	{  printf("\nfor processes %d :",i+1);
		scanf("%d",&arrivalTime[i]);
	}
	printf("\nenter burst time for processes:");
	for(i=0;i<m;i++)
	{
		printf("\nfor processes %d:",i+1);
		scanf("%d",&burst[i]);
		burst1[i] = burst[i];	
	}
	printf("First IterarrivalTimeion(TQ=3)\n");
	for(i=0;i<m;i++)
	{  
	if(arrivalTime[i] <= tq1+arrivalTime[i-1])
	{
	
		burst[i] = burst[i] - tq1;
		
		printf("\nprocess %d",i+1);
		printf("\nLeft=%d",burst[i]);}
		else
		{
		burst[i] = burst[i] - tq1;
	
		printf("\nprocess %d ",i+1);
		printf("\nLeft= %d",burst[i]);	
		}}
	
	printf("\nAFTER ITERarrivalTimeION 2 (TQ=6)");
	for(i=0;i<m;i++)
	{
	if(arrivalTime[i] <= tq2+arrivalTime[i-1])
	{
	
		burst[i] = burst[i] - tq2;
		
		printf("\nprocess %d",i+1);
		printf("\nLeft= %d",burst[i]);}
		else
		{
		burst[i] = burst[i] - tq2;
	
		printf("\nprocess %d",i+1);
		printf("\nLeft= %d",burst[i]);	
		}	
	}
	printf("\n3RD ITERarrivalTimeION");
	int j,temp;

	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{if(burst[i]>burst[j])
		{
		
			temp = burst[i];
			burst[i] = burst[j];
			burst[j] = temp;
			}
		}
	}
	int ct[4] = {54,68,45,41};
	for(i=0;i<m;i++)
	{
		tarrivalTime[i] = ct[i] - arrivalTime[i];
		waiting[i] = tarrivalTime[i] - burst1[i];
		printf("\nCompletion time for process%d:%d \n",i+1,ct[i]);
		printf("Turn arround time for process:%d:%d \n",i+1,tarrivalTime[i]);
		printf("Waiting time for process:%d : %d \n",i+1,waiting[i]);
		avgT = avgT + tarrivalTime[i];
		avgW = avgW + waiting[i];
		
	}
	avgT = avgT / m;
	avgW = avgW / m;
	printf("\nAverage turn arrounf time: %d",avgT);
	printf("\nAverage waiting time: %d",avgW);
	}
