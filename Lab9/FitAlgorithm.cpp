#include <iostream>
using namespace std;

void firstFit(int hole[],int n,int process[],int np)
{
    cout<<endl;
    cout<<endl;
    cout<<"FIRST FIT ALLOCATION\n";
    for(int i=0;i<np;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(process[i]<=hole[j]){
                flag=1;
                cout<<"\nP"<<i+1<<"of size "<<process[i]<<" fitted in hole of size "<<hole[j]<<endl;
                hole[j]-=process[i];
                cout << "Hole representation: ";
                for (int k = 0; k < n; k++)
                {
                    cout << hole[k] << " -> ";
                }
                cout<<endl;
                break;
            }
        }
        if(!flag){
            cout<<"\nP"<<i+1<<" cannot be fitted into any hole";
        }
    }
}

void bestFit(int hole[],int n,int process[],int np){
    cout<<endl;
    cout<<endl;
    cout<<"BEST FIT ALLOCATION\n";
    for(int i=0;i<np;i++){
        int small=INT_MAX;
        int pos=-1;
        for(int j=0;j<n;j++){
            if(process[i]<=hole[j] && hole[j]<small){
                small=hole[j];
                pos=j;
            }
        }
        if(small==INT_MAX){
            cout<<"\nP"<<i+1<<" cannot be fitted into any hole";
        }
        else{
            cout<<"\nP"<<i+1<<"of size "<<process[i]<<" fitted in hole of size "<<hole[pos]<<endl;
            hole[pos]-=process[i];
            cout << "Current hole representation: ";
            for (int k = 0; k < n; k++)
            {
                cout << hole[k] << " -> ";
            }
            cout<<endl;
        }
    }
}

void worstFit(int hole[],int n,int process[],int np){
    cout<<endl;
    cout<<endl;
    cout<<"WORST FIT ALLOCATION\n";
    for(int i=0;i<np;i++){
        int small=INT_MIN;
        int pos=-1;
        for(int j=0;j<n;j++){
            if(process[i]<=hole[j] && hole[j]>small){
                small=hole[j];
                pos=j;
            }
        }
        if(small==INT_MIN){
            cout<<"\nP"<<i+1<<" cannot be fitted into any hole";
        }
        else{
            cout<<"\nP"<<i+1<<"of size "<<process[i]<<" fitted in hole of size "<<hole[pos]<<endl;
            hole[pos]-=process[i];
            cout << "Current hole representation: ";
            for (int k = 0; k < n; k++)
            {
                cout << hole[k] << " -> ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    int n, ch;
    cout << "Enter number of holes: ";
    cin >> n;
    int hole[n];
    cout << "Enter respective hole capacities: ";
    for (int i = 0; i < n; i++)
    {
        cin >> hole[i];
    }
    cout << "\nHole representation: ";
    for (int i = 0; i < n; i++)
    {
        cout << hole[i] << " -> ";
    }
    int np;
    cout<<"\nEnter number of processes: ";
    cin>>np;
    int process[np];
    cout << "Enter respective process sizes: ";
    for(int i=0;i<np;i++){
        cin>>process[i];
    }
    cout << "\nMENU\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\nEnter your choice: ";
    cin >> ch;
    if (ch == 1)
    {
        firstFit(hole,n,process,np);
    }
    else if (ch == 2)
    {
        bestFit(hole,n,process,np);
    }
    else if (ch == 3)
    {
        worstFit(hole,n,process,np);
    }
    else
    {
        cout << "Exiting...";
        return 0;
    }
    // 4 100 200 300 150 4 90 145 10 5 
    return 0;
}