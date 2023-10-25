#include <stdio.h>
#include <stdlib.h>

void SJF(){
    int n,wait=0,turnaround=0,timer=0,smallestBT=999,small=999;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int *CT = (int *)malloc((n+1)*sizeof(int));
    int *AT = (int *)malloc((n+1)*sizeof(int));
    int *BT = (int *)malloc((n+1)*sizeof(int));
    int *p = (int *)malloc((n+1)*sizeof(int));
    int *visited = (int *)malloc((n+1)*sizeof(int));
    printf("\nEnter arrival time, burst time: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&AT[i]);
        scanf("%d",&BT[i]);
        p[i] = i+1;
    }
    for(int i=0;i<n;i++){
      visited[i]=0;
    }
    for(int i=0;i<n;i++){
      if(AT[i]<small){
        small=AT[i];
      }
    }
    while(timer!=small){
        timer++;
    }
    printf("\n\nNon-Preemptive SJF\n");
    for(int i=0;i<n;i++){
        smallestBT=999;
        small=999;
        for(int j=0;j<n;j++){
            if(visited[j]==0 && AT[j]<=timer && BT[j]<smallestBT){
                smallestBT = BT[j];
                small = j;
            }   
        }
        visited[small]=1;
        printf("Process %d -> (%d %d)\n",p[small],timer,timer+BT[small]);
        timer+=BT[small];
        CT[small]=timer;
    }
    for(int i=0;i<n;i++){
        turnaround+=(CT[i]-AT[i]);
        wait+=(CT[i]-AT[i]-BT[i]);
    }
    printf("\nAverage Waiting Time: %f",(float)wait/n);
    printf("\nAverage Turnaround Time: %f",(float)turnaround/n);
}

int main(){
    SJF();
}

/*
0 10
2 5
4 3
11 9
*/

/*
1 0 10 1
2 2 5 1
3 4 3 1
4 11 9 1
*/