#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
    int id,AT,BT,CT,RT;
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

void SRTF(Process p[],int n){
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
        for(int i=0;i<n;i++){
            if(p[i].AT<=timer && p[i].RT<min && p[i].RT!=0){
                min=p[i].RT;
                pos=i;
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
        cout<<"\nEnter AT and BT for P"<<i+1<<": ";
        p[i].id=i+1;
        cin>>p[i].AT>>p[i].BT;
        p[i].RT=p[i].BT;
    }
    cout<<endl;
    SRTF(p,n);
    return 0;
}

/*
5
2 6
5 2
1 8
0 3
4 4
*/