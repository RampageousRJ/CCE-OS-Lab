#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Process{
    public:
    int id;
    int AT;
    int BT;
    bool visited;
    Process(){
        visited=false;
    }
};

void BubbleSortArrival(Process p[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].AT>p[j+1].AT){
                swap(p[j],p[j+1]);
            }
        }
    }
}

void SJF(){
    int n,wait=0,turnaround=0,timer=0,smallestBT=999,small=999;
    cout<<"Enter number of processes: ";
    cin>>n;
    Process *p = (Process *)malloc((n)*sizeof(Process));
    int *CT = (int *)malloc(n*sizeof(int));
    cout<<"\nEnter arrival time, burst time: \n";
    for(int i=0;i<n;i++){
        cin>>p[i].AT>>p[i].BT;
        p[i].id = i+1;
    }
    int i=0;
    BubbleSortArrival(p,n);
    while(timer!=p[i].AT){
        timer++;
    }
    for(int i=0;i<n;i++){
        smallestBT=999;
        small=999;
        for(int j=0;j<n;j++){
            if(!p[j].visited && p[j].AT<=timer && p[j].BT<smallestBT){
                smallestBT = p[j].BT;
                small = j;
            }   
        }
        p[small].visited=true;
        cout<<"Process "<<p[small].id<<" -> ("<<timer<<" "<<timer+p[small].BT<<")\n";
        timer+=p[small].BT;
        CT[small]=timer;
    }
    for(int i=0;i<n;i++){
        turnaround+=(CT[i]-p[i].AT);
        wait+=(CT[i]-p[i].AT-p[i].BT);
    }
    cout<<"\nAverage Waiting Time: "<<(float)wait/n;
    cout<<"\nAverage Turnaround Time: "<<(float)turnaround/n;
}

int main(){
    SJF();
}