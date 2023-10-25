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

bool contains(list<int> &l1,int key){
    list<int>::iterator it;
    for(it=l1.begin();it!=l1.end();it++){
        if(*it==key){
            return true;
        }
    }
    return false;
}

int find(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int opr(int nf,int n){
    list<int>::iterator it;
    int arr[nf];
    for(int i=0;i<nf;i++){
        arr[i]=-1;
    }
    int ref[n],page_fault=0;
    cout<<"Enter reference string: ";
    for(int i=0;i<n;i++){
        cin>>ref[i];
    }
    cout<<endl;
    int pos=0;
    list<int> l1;
    for(int i=0;i<n;i++){
        if(contains(arr,nf,ref[i])){
            continue;
        }
        else if(contains(arr,nf,-1)){
            page_fault++;
            arr[pos++]=ref[i];
        }
        else{
            page_fault++;
            int pos=0;
            for(int k=0;k<nf;k++){
                l1.push_back(arr[k]);
            }
            for(int j=i;j<n;j++){
                if(contains(l1,ref[j])){
                    l1.remove(ref[j]);
                    if(l1.size()==1){
                        break;
                    }
                }
            }
            pos=find(arr,nf,l1.back());
            arr[pos]=ref[i];
            while(!l1.empty()){
                l1.pop_back();
            }
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
    int pf = opr(nf,n);
    cout<<"\nNumber of page faults: "<<pf;
    // 3 20 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
}