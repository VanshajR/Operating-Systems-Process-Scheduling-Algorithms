#include<stdio.h>
int main()
{
	int i,j,n,temp,tot=0,count=0;
	float avg_tat=0, avg_wt=0;
	printf("N: ");
	scanf("%d",&n);
	int at[n],bt[n],ct[n],wt[n],tat[n],og_bt[n],swap_bt[n],og_at[n],st[n],curr[n],order[n];
	for(i=0;i<n;i++)
	{
		printf("P%d\n",i+1);
		printf("AT: ");
		scanf("%d",&at[i]);
		printf("BT: ");
		scanf("%d",&bt[i]);
		og_at[i]=at[i];
		og_bt[i]=bt[i];
		order[i]=i;
		printf("\n");
	}
	printf("after input\n");
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
		swap_bt[i]=bt[i];
	}
	while(count<n)
	{
		int sbt=-1;
		int index=-1;
		for(i=0;i<n;i++)
		{
			if(at[i]<=tot&&bt[i]>0)
			{
				if(sbt==-1||bt[i]<sbt)
				{
					sbt=bt[i];
					index=i;
				}
				
			}
		}
		if(index==-1)
		{
			tot++;
			continue;
		}
		curr[index]=order[index];
		st[index]=tot;
		ct[index]=tot+bt[index];
		tot=ct[index];
		bt[index]=0;
		count++;
	}
	printf("after while\n");
	for(j=0;j<n;j++)
	{
		i=curr[j];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-swap_bt[i];
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	avg_tat/=n;
	avg_wt/=n;
	printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		int x=curr[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",x+1,og_at[x],og_bt[x],st[i],ct[i],tat[i],wt[i]);
	}
	printf("AVG TAT: %f\n",avg_tat);
	printf("AVG WT: %f",avg_wt);
	return 0;
}