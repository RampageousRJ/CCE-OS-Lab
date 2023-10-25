#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
    int id,AT,BT,CT,RT,P;
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

void PriorityP(Process p[],int n){
    sortAT(p,n);
    int timer=0;
    while(timer!=p[0].AT){
        timer++;
    }
    int sum=0;
    float TAT=0,WT=0;
    for(int i=0;i<n;i++){
        sum+=p[i].BT;
    }
    while(timer<sum){
        int min=INT_MAX;
        int pos=-1;
        int prior=-1;
        for(int i=0;i<n;i++){
            if(p[i].AT<=timer  && p[i].RT!=0 && p[i].P>prior){
                min=p[i].RT;
                pos=i;
                prior=p[i].P;
            }
        }
        if(min==INT_MAX){
            timer++;
        }
        else{
            p[pos].RT--;
            timer++;
            if(p[pos].RT==0){
                p[pos].CT=timer;
                cout<<"\nP"<<p[pos].id<<" completed at t="<<timer;
                TAT+=(p[pos].CT-p[pos].AT);
                WT+=(p[pos].CT-p[pos].AT-p[pos].BT);
            }
        }
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
        cout<<"\nEnter Priority, AT and BT for P"<<i+1<<": ";   
        p[i].id=i+1;
        cin>>p[i].P>>p[i].AT>>p[i].BT;
        p[i].RT=p[i].BT;
    }
    cout<<endl;
    PriorityP(p,n);
    return 0;
}

/*
7
2 0 1
6 1 7
3 2 3
5 3 6
4 4 5
10 5 15
9 15 8
*/

/*
5
2 0 4
3 1 3
4 2 1
5 3 5
5 4 2
*/