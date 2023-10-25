#include <iostream>
using namespace std;

void sort(int queue[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(queue[j]>queue[j+1]){
                swap(queue[j],queue[j+1]);
            }
        }
    }
}

int find(int queue[],int n,int key){
    for(int i=0;i<n;i++){
        if(queue[i]==key){
            return i;
        }
    }
    return -1;
}

int CLOOK(int queue[],int n,int header){
    sort(queue,n);
    cout<<"ARRAY: ";
    for(int i=0;i<n;i++){
        cout<<queue[i]<<" ";
    }
    int pos = find(queue,n,header);
    int prev=header;
    int sum=0;
    for(int i=pos;i>=0;i--){
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    prev=queue[n-1];
    for(int i=n-2;i>=pos+1;i--){
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter number of tracks: ";
    cin>>n;
    int queue[n+1];
    cout<<"Enter tracks: ";
    for(int i=0;i<n;i++){
        cin>>queue[i];
    }
    int header;
    cout<<"Enter header: ";
    cin>>header;
    queue[n]=header;
    int val=CLOOK(queue,n+1,header);
    cout<<endl<<"Overhead time: "<<val;
    return 0;
}

/*
8
95 180 34 119 11 123 62 64 
50
*/  