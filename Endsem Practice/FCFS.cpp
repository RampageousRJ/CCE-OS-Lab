#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
    int id,AT,BT,CT;
};

void sortAT(Process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].AT>p[j+1].AT){
                swap(p[j],p[j+1]);
            }
        }
    }
}

void FCFS(Process p[],int n){
    sortAT(p,n);
    int timer=0;
    while(timer!=p[0].AT){
        timer++;
    }
    float WT,TAT;
    for(int i=0;i<n;i++){
        timer+=p[i].BT;
        p[i].CT=timer;
        TAT+=(p[i].CT-p[i].AT);
        WT+=(p[i].CT-p[i].AT-p[i].BT);
        cout<<"\nP"<<p[i].id<<" completed at t="<<timer;
    }
    WT/=n;
    TAT/=n;
    cout<<"\n\nAverage Waiting Time: "<<WT;
    cout<<"\nAverage Turnaround Time: "<<TAT;
}

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    Process p[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter AT and BT for P"<<i+1<<": ";
        p[i].id=i+1;
        cin>>p[i].AT>>p[i].BT;
    }
    cout<<endl;
    FCFS(p,n);
    return 0;
}