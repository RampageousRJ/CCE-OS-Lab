#include <iostream>
using namespace std;

int SSTF(int queue[],int n,int header){
    int visited[n]={0};
    int sum=0;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int pos=-1;
        for(int j=0;j<n;j++){
            int dist=(header-queue[j]);
            if(dist<0){
                dist*=-1;
            }
            if(dist<min && !visited[j]){
                min=dist;
                pos=j;
            }
        }
        visited[pos]=true;
        header=queue[pos];
        sum+=min;
    }
    return sum;
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
    int val = SSTF(queue,n,header);
    cout<<"Overhead tracks: "<<val;
    return 0;
}

/*
8
95 180 34 119 11 123 62 64 
50
*/ 