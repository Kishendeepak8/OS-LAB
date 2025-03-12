
#include<stdio.h>
int main()
{

    int n;
    printf("enter the number of processes:");
    scanf("%d",&n);
    int wt[n],tat[n],bt[n];
    float wtavg=0,tatavg=0;
    for(int i=0;i<n;i++)
    {
        printf("\n enter the burst time for process%d: ",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    wtavg=(wt[0]+wtavg)/n;
    tatavg=(tat[0]+tatavg)/n;
     printf("\nprocess\tburst time\twaiting time\tturnaround time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\naverage waiting time = %.2f", wtavg);
    printf("\naverage turnaround time = %.2f", tatavg);

    return 0;
}

