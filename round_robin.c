#include<stdio.h>
int main() {
    int i, n, quantum, tot=0,count=0;
    float avg_tat = 0, avg_wt = 0;

    printf("N: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], og_bt[n], og_at[n], st[n], order[n], curr[n];

    for (i = 0; i < n; i++) {
        printf("P%d\n", i + 1);
        printf("AT: ");
        scanf("%d", &at[i]);
        printf("BT: ");
        scanf("%d", &bt[i]);
        og_at[i] = at[i];
        og_bt[i] = bt[i];
        order[i] = i+1;
        printf("\n");
    }

    printf("Quantum: ");
    scanf("%d", &quantum);

    while (count<n) {

        	if(tot<at[0]){tot=at[0];}
        for (i = 0; i < n; i++) {
            int done=0;
            if (at[i]<=tot&&bt[i] > 0) {
                if (bt[i] > quantum) {
                    tot += quantum;
                    bt[i] -= quantum;
                    if(done==0)
                    {
                	    st[i] = tot-quantum;
                        done++;
                    }
                    printf("Process %d executed from %d to %d\n",order[i],tot-quantum,tot);
                } else {
                    ct[i]=tot+bt[i];
                    tot=ct[i];
                    tat[i] = ct[i] - at[i];
        			wt[i] = tat[i] - og_bt[i];
        			avg_wt += wt[i];
        			avg_tat += tat[i];
                    if(done==0)
                    {
                	    st[i] = tot-bt[i];
                        done++;
                    }
        			printf("Process %d executed from %d to %d\n",order[i],tot-bt[i],tot);
                    bt[i] = 0;
                    count++;
                    
                }
            }
        }
    }
    st[0]=at[0];
    avg_tat /= n;
    avg_wt /= n;
    printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, og_at[i], og_bt[i], st[i], ct[i], tat[i], wt[i]);
    }
    printf("AVG TAT: %f\n", avg_tat);
    printf("AVG WT: %f", avg_wt);
    return 0;
}
