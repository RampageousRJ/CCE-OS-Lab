#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool contains(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int fifo(int nf,int n){
    int arr[nf];
    for(int i=0;i<nf;i++){
        arr[i]=-1;
    }
    int page_fault=0;
    int ref[n],pos=0;
    cout<<"Enter reference string: ";
    for(int i=0;i<n;i++){
        cin>>ref[i];
    }
    for(int i=0;i<n;i++){
        if(!contains(arr,nf,ref[i])){
            page_fault++;
            arr[pos]=ref[i];
            pos=((pos+1)%nf);
        }
    }
    return page_fault;
}

int main(){
    int nf,n;
    cout<<"Enter number of frames: ";
    cin>>nf;
    cout<<"Enter number of pages: ";
    cin>>n;
    int pf = fifo(nf,n);
    cout<<"\nNumber of page faults: "<<pf;
}