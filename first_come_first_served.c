#include<stdio.h>
int main()
{
	int i,j,n,temp,tot=0;
	float avg_wt=0, avg_tat=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	int at[n],bt[n],ct[n],wt[n],tat[n],order[n];
	for(i=0;i<n;i++)
	{
		printf("Enter details of process %d:-\n",i+1);
		printf("Enter arrival time: ");
		scanf("%d",&at[i]);
		printf("Enter burst time: ");
		scanf("%d",&bt[i]);
		order[i]=i+1;
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=order[i];
				order[i]=order[j];
				order[j]=temp;
				
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;		
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(tot<at[0])
		{
			tot=at[0];
		}
		ct[i]=tot+bt[i];
		tot=ct[i];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];

		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	avg_wt/=n;
	avg_tat/=n;
	
	printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",order[i],at[i],bt[i],ct[i]-bt[i],ct[i],tat[i],wt[i]);
	}
	printf("Average Waiting Time: %f\n",avg_wt);
	printf("Average Tunr Around Time: %f\n",avg_tat);
	return 0;
}