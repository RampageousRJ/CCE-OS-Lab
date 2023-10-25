#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>   
#include <unistd.h>   
	
typedef struct
{
    int pid;
    int AT;
    int BT;
    int RT;
	    int priority;
}Process;
	
Process* Input()
{
    printf("No. of Processes:");
    int n;
    scanf("%d", &n);
    fflush(stdin);
    Process* p = (Process*) malloc( n+1 * sizeof(Process) );
    printf("Enter PID, Arrival Time, Burst Time, Priority\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d :",i+1);
        scanf("%d %d %d %d", &p[i].pid, &p[i].AT, &p[i].BT, &p[i].priority);
        fflush(stdin);
        p[i].RT=p[i].BT;
    }
    p[n].pid=-1;
    return p;
}
	
int min(Process *p, int n, int timer)
{
    int min_time=9999;
    int min=-1;
    for(int i=0;i<n;i++)
    {
        if(p[i].AT<=timer && p[i].RT>0 && p[i].BT<min_time)
        {
            min_time=p[i].BT;
            min=i;
        }
    }
	   return min;
}	
void ShortestJobFirst()
{
    Process* p =Input();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    int timer=0;
    float TAT=0;
    float WAT=0;
    int done=0;
    while(done!=n)
    {
        int i = min(p,n,timer);
        int start=timer;
        int j=i;
        int ran = p[i].RT;
        while(j==i)
        {
	       timer++;
           p[i].RT--;
	       j=min(p,n,timer);
        }
        printf("P%d -> (%d %d)\n", p[i].pid, start, timer);
        if(p[i].RT==0)
        {
	        TAT+=(timer-p[i].AT);
            WAT+=(timer-p[i].AT-p[i].BT);       
            done++;
	    }
    }
    TAT=TAT/n;
    WAT=WAT/n;
    printf("Turnaround Time = %0.2f ms \n", TAT);
    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}
	
void RR()
{
    Process* p = Input();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    int q;
    printf("Enter time slice:");
    scanf("%d", &q);
    int timer=0;
    int done=0;
    float TAT=0;
    float WAT=0;
    while(done!=n)
    {
        for(int i=0;i<n;i++)
        {
            int count=q;
            int start=timer;
            while(p[i].RT>0 && p[i].AT<=timer && count>0)
            {
                timer++;
                p[i].RT--;
    	        count--;
    	    }
            if(start!=timer)
            {
                printf("P%d -> (%d %d)\n", p[i].pid, start, timer);
                if(p[i].RT==0)
                {
    	            TAT+=(timer-p[i].AT);
                    WAT+=(timer-p[i].AT-p[i].BT);
    	            done++;
        	    }
            }
    	}
    }
	TAT=TAT/n;
    WAT=WAT/n;
    printf("Turnaround Time = %0.2f ms \n", TAT);
    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}
	
int comparator(const void* p, const void* q) 
{ 
	    return ((Process*)p)->AT > ((Process*)q)->AT && ((Process*)p)->priority > ((Process*)q)->priority;
}

void Priority()
{
	    Process* p =Input();
	    int n=0;
	    while(p[n].pid!=-1) n++;
	    qsort(p, n, sizeof(Process), comparator);
	    int timer=0;
	    float TAT=0;
        float WAT=0;
	    for(int i=0;i<n;i++)
	    {
	        WAT+=(timer-p[i].AT);
	        printf("P%d -> (%d %d)\n",p[i].pid, timer, timer+p[i].BT);
            timer+=p[i].BT;
	        TAT+=(timer-p[i].AT);
	    }
	    TAT=TAT/n;
	    WAT=WAT/n;
	    printf("Turnaround Time = %0.2f ms \n", TAT);
	    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}	

int main()
{
    int ch;
    while(1)
    {
        printf("1. Shortest Job First (PreEmptive)\n");
        printf("2. Round Robin (PreEmptive)\n");
        printf("3. Priority Scheduling (Non-PreEmptive)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                ShortestJobFirst();
                break;
            case 2:
                RR();
                break;
            case 3:
                Priority();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice... \n");
        }
    }
}