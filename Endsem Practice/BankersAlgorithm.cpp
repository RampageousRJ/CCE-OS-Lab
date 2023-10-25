#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter number of processes and resources: ";
    cin>>n>>m;
    int M[n][m],A[n][m],N[n][m],total[m],Av[m];
    cout<<"Enter total resources: ";
    for(int i=0;i<m;i++){
        cin>>total[i];
    }
    cout<<"\nEnter max matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>M[i][j];
        }
    }
    cout<<"\nEnter allocated matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            N[i][j]=M[i][j]-A[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=A[j][i];
        }
        Av[i]=total[i]-sum;
    }
    cout<<"\n\nAvailable Resources: \n";
    for(int j=0;j<m;j++){
        cout<<Av[j]<<" ";
    }
    vector<int> safe;
    int visited[n]={0};
    for(int k=0;k<n-1;k++){
        int count=0;
        for(int i=0;i<n;i++){
            int flag=1;
            if(!visited[i]){
                for(int j=0;j<m;j++){
                    if(Av[j]<N[i][j]){
                        flag=0;
                    }
                }
            }
            if(flag && !visited[i]){
                cout<<endl;
                count++;
                safe.push_back(i+1);
                visited[i]=true;
                for(int j=0;j<m;j++){
                    Av[j]+=A[i][j];
                    cout<<Av[j]<<" ";
                }
            }
        }
        if((signed)safe.size()==n){
            break;
        }
        if(count==0){
            cout<<"\n\nUNSAFE";
            return 0;
        }
    }
    vector<int>::iterator it;
    cout<<"\n\nSAFE SEQUENCE: ";
    for(unsigned int i=0;i<safe.size();i++){
        cout<<safe[i]<<" -> ";
    }
    return 0;
}

/*
UNSAFE SEQUENCE
5 3

10 5 7

7 5 3
3 2 2
9 0 2
4 2 2
5 3 3

2 1 0
2 0 0
2 0 2
2 1 1
2 0 2

SAFE SEQUENCE
5 3

10 5 7

7 5 3
3 2 2
9 0 2
4 2 2
5 3 3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
*/