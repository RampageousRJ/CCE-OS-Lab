#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
    int id,AT,BT,CT,RT;
};

void RR(Process p[],int n){
    int timer=0,q;
    cout<<"Enter time quantum: ";
    cin>>q;
    while(timer!=p[0].AT){
        timer++;
    }
    int sum=0;
    float TAT=0,WT=0;
    for(int i=0;i<n;i++){
        sum+=p[i].BT;
    }int complete=0;
    while(complete<n){
        for(int i=0;i<n;i++){
            if(p[i].AT<=timer && p[i].RT!=0){
                if(p[i].RT<q){
                    timer+=p[i].RT;
                    p[i].RT=0;
                    complete++;
                    p[i].CT=timer;
                    cout<<"Process"<<p[i].id<<" completed at t="<<timer<<endl;
                    TAT+=(p[i].CT-p[i].AT);
                    WT+=(p[i].CT-p[i].AT-p[i].BT);
                }
                else{
                    timer+=q;
                    p[i].RT-=q;
                    if(p[i].RT==0){
                        complete++;
                        p[i].CT=timer;
                        cout<<"Process"<<p[i].id<<" completed at t="<<timer<<endl;
                        TAT+=(p[i].CT-p[i].AT);
                        WT+=(p[i].CT-p[i].AT-p[i].BT);
                    }
                }
            }
        }
    }
    cout<<"\n\nAverage Waiting Time: "<<WT/n;
    cout<<"\nAverage Turnaround Time: "<<TAT/n;
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
    RR(p,n);
    return 0;
}

/*
4
0 5
1 4
2 2
3 1
2
*/