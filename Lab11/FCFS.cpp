#include <iostream>
using namespace std;

int FCFS(int queue[],int n,int header){
    int otime=0;
    int prev=header;
    for(int i=0;i<n;i++){
        int temp =(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        otime+=temp;
        prev=queue[i];
    }
    return otime;
}

int main(){
    int n;
    cout<<"Enter number of tracks: ";
    cin>>n;
    int queue[n];
    cout<<"Enter tracks: ";
    for(int i=0;i<n;i++){
        cin>>queue[i];
    }
    int header;
    cout<<"Enter header: ";
    cin>>header;
    cout<<"Overhead time: "<<FCFS(queue,n,header);
    return 0;
}

/*
8
95 180 34 119 11 123 62 64 
50
*/  