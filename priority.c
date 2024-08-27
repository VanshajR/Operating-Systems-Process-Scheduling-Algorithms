#include<stdio.h>
int main()
{
	int i,j,n,temp,tot=0,count=0;
	float avg_tat=0, avg_wt=0;
	printf("N: ");
	scanf("%d",&n);
	int at[n],bt[n],ct[n],wt[n],tat[n],og_at[n],og_bt[n],pri[n],og_pri[n],swap_bt[n],st[n],curr[n],order[n];
	for(i=0;i<n;i++)
	{
		printf("P%d\n",i+1);
		printf("AT: ");
		scanf("%d",&at[i]);
		printf("BT: ");
		scanf("%d",&bt[i]);
		printf("PRI: ");
		scanf("%d",&pri[i]);
		order[i]=i;
		og_bt[i]=bt[i];
		og_at[i]=at[i];
		og_pri[i]=pri[i];
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]>at[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=order[i];
				order[i]=order[j];
				order[j]=temp;
				
				temp=pri[i];
				pri[i]=pri[j];
				pri[j]=temp;
				
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
			}
		}
		swap_bt[i]=bt[i];
	}
	while(count<n)
	{
		int hp=9999;
		int index=-1;
		for(i=0;i<n;i++)
		{
			if(at[i]<=tot&&bt[i]>0)
			{
				if(pri[i]<hp)
				{
					hp=pri[i];
					index=i;
				}
			}
		}
		if(index==-1)
		{
			tot++;
			continue;
		}
		st[index]=tot;
		ct[index]=tot+bt[index];
		tot=ct[index];
		curr[index]=order[index];
		bt[index]=0;
		count++;
	}
	for(j=0;j<n;j++)
	{
		i=curr[j];
		tat[i]=ct[i]-at[j];
		wt[i]=tat[i]-swap_bt[i];
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	avg_wt/=n;
	avg_tat/=n;
	printf("Process\tPriority\tAT\tBT\tST\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		int x=curr[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",x+1,og_pri[x],og_at[x],og_bt[x],st[i],ct[i],tat[i],wt[i]);
	}
	printf("AVG TAT: %f\n",avg_tat);
	printf("AVG WT: %f",avg_wt);
	return 0;
}