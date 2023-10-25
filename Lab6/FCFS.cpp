#include <iostream>
#include <cstdlib>
using namespace std;

class Process{
    public:
    int id;
    int AT;
    int BT;
};

void BubbleSort(Process p[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].AT>p[j+1].AT){
                swap(p[j],p[j+1]);
            }
        }
    }
}

void FCFS(){
    int n,total=0,wait=0,k=0,turnaround=0;
    cout<<"Enter number of processes: ";
    cin>>n;
    Process *p = (Process *)malloc((n)*sizeof(Process));
    int *CT = (int *)malloc(n*sizeof(int));
    cout<<"\nEnter arrival time, burst time: \n";
    for(int i=0;i<n;i++){
        cin>>p[i].AT>>p[i].BT;
        p[i].id = i+1;
    }
    BubbleSort(p,n);
    cout<<"\n\nFCFS Sequence\n";
    int i=0;
    while(total!=p[i].AT){
        total++;
    }
    for(i=0;i<n;i++){
        cout<<"Process "<<p[i].id<<" -> ("<<total<<" "<<total+p[i].BT<<")\n";
        total+=p[i].BT;
        CT[k++]=total;
    }
    for(int i=0;i<n;i++){
        turnaround+=(CT[i]-p[i].AT);
        wait+=(CT[i]-p[i].AT-p[i].BT);
    }
    cout<<"\nAverage Waiting Time: "<<(float)wait/n;
    cout<<"\nAverage Turnaround Time: "<<(float)turnaround/n;
}

int main(){
    FCFS();
}