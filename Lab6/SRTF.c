#include <stdio.h>
#include <stdlib.h>

struct Process{
    int id,AT,BT,RT;
};

void SRTF(struct Process* p,int n){
    int timer=0,small=999,smallest_RT=-1,comp=0,TAT=0,WT=0;
    for(int i=0;i<n;i++){
        if(p[i].AT<small){
            small=p[i].AT;
        }
    }
    while(timer!=small){
        timer++;
    }
    printf("\n\nPre-emptive SJF\n");
    while(comp<n){
        smallest_RT=-1;
        for(int i=0;i<n;i++){
            if(p[i].AT<=timer && p[i].RT>0 && (p[i].RT<smallest_RT || smallest_RT==-1)){
                smallest_RT=p[i].RT;
                small=i;
            }
        }
        if(smallest_RT==-1){
            timer++;
        }
        else{
            p[small].RT--;
            timer++;
            if(p[small].RT==0){
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
    struct Process* p = (struct Process *)malloc(n*sizeof(struct Process));
    printf("\n\nEnter AT and BT for the processes\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].RT=p[i].BT;
        p[i].id=i+1;
    }
    SRTF(p,n);
}

/*0 10
2 5
4 3
11 9*/