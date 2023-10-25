#include <stdio.h>
#include <stdlib.h>

struct Process{
    int id,AT,BT,RT,CT;
};

void RR(struct Process* p,int n){
    int smallest_BT=-1,small=999,TAT=0,WT=0,timer=0,q,comp=0;
    printf("Enter time quantum: ");
    scanf("%d",&q);
    for(int i=0;i<n;i++){
        if(p[i].AT<small){
            small=p[i].AT;
        }
    }
    while(timer!=small){
        timer++;
    }
    printf("\n\nRound Robin\n");
    while(comp<n){
        smallest_BT=-1;
        for(int i=0;i<n;i++){
            if(p[i].AT<=timer && p[i].RT>0 && (smallest_BT==-1 || p[i].RT<smallest_BT)){
                smallest_BT=p[i].RT;
                small=i;
            }
        }
        if(smallest_BT==-1){
            timer++;
        }
        else{
            p[small].RT-=q;
            if(p[small].RT>=0){
                timer+=q;
            }
            else{
                timer+=(p[small].RT+q+1);
            }
            if(p[small].RT<1){
                printf("P%d completes execution at %d\n",small+1,timer);
                TAT+=(timer-p[small].AT);
                WT+=(timer-p[small].AT-p[small].BT);
                comp++;
            }
        }
    }
    printf("\nAverage Turnaround Time: %0.2f",(float)TAT/n);
    printf("\nAverage Waiting Time: %0.2f",(float)WT/n);
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    struct Process* p = (struct Process*)malloc(n*sizeof(struct Process));
    printf("\nEnter AT and BT for the processes: \n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].RT = p[i].BT;
        p[i].id=i+1;
    }
    RR(p,n);
    return 0;
}