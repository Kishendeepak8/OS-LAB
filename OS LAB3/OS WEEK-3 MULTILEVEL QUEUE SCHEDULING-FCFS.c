#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid;
    int completion_time;
    int burst_time;
    };
int completion_time(struct process s[],int n,int start_time){
    s[0].completion_time=start_time+s[0].burst_time;
    for(int i=1;i<n;i++)
    {
        s[i].completion_time=s[i-1].completion_time+s[i].burst_time;
    }
}
int result(struct process s[],int n){
printf("\n  PID\t  Burst time\t  Completion time\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t\t\t%d\n",s[i].pid,s[i].burst_time,s[i].completion_time);
}
}
void multilevel_queue(struct process s[],int sn,struct process u[],int un){
    printf("executing higher order system process:\n");
    completion_time(s,sn,0);
    result(s,sn);

    printf("executing the lower order user process:\n");
    int last_completiontime=sn>0?s[sn-1].completion_time:0;
    completion_time(u,un,last_completiontime);
    result(u,un);
}
int main(){
int sn,un;
printf("\nenter the number of processes in system process:");
scanf("%d",&sn);
struct process s[sn];
for(int i=0;i<sn;i++){
    s[i].pid=i+1;
    printf("\nenter the burst time for P%d:",s[i].pid);
    scanf("%d",&s[i].burst_time);
}
printf("\nenter the number of processes in user process:");
scanf("%d",&un);
struct process u[un];
for(int i=0;i<un;i++){
    u[i].pid=i+1+sn;
    printf("\nenter the burst time for P%d:",u[i].pid);
    scanf("%d",&u[i].burst_time);
}
multilevel_queue(s,sn,u,un);
return 0;
}

