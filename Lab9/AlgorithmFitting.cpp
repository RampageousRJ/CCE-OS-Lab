#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node(int ele){
        val=ele;
        next=NULL;
    }
};

Node *insert_end(Node *head,int val){
    Node *temp=new Node(val);
    if(!head){
        return temp;
    }
    Node *t=head;
    while(t->next){
        t=t->next;
    }
    t->next=temp;
    return head;
}

void display(Node *head){
    Node *t=head;
    for(;t;t=t->next){
        cout<<t->val<<" -> ";
    }
}

Node* firstFit(Node *head, int val){
    Node *t=head;
    for(;t;t=t->next){
        if(val <= t->val){
            cout<<"Process fitted into hole with size "<<t->val;
            t->val -= val;
            return head;
        }
    }
    cout<<"Cannot be fitted";
    return head;
}

Node* bestFit(Node *head, int val){
    Node *t=head;
    Node *ptr;
    int small=999;
    for(;t;t=t->next){
        if(val <= t->val && t->val <= small){
            ptr=t;
            small=t->val;
        }
    }
    if(ptr->val!=999){
        cout<<"Process fitted into hole with size "<<ptr->val;
        ptr->val -= val;
    }
    else{
        cout<<"Cannot be fitted";
    }
    return head;
}

int main(){
    Node *head=NULL;
    int n,val,m,k=0,ch;
    cout<<"Enter number of holes: ";
    cin>>n;
    cout<<"\nEnter sizes of holes: ";
    int size[n];
    for(int i=0;i<n;i++){
        cin>>val;
        size[k]=val;
        head=insert_end(head,size[i]);
    }
    cout<<"\n\nHOLES AND SPACES: ";
    display(head);
    cout<<"\n\nMENU\n1.First Fit\n2.Best Fit\nEnter your choice: ";
    cin>>ch;
    if(ch==1){
        cout<<"\nEnter total number of processes: ";
        cin>>m;
        for(int i=0;i<m;i++){
            cout<<"\nEnter size: ";
            cin>>val;
            head=firstFit(head,val);
        }
    }
    else if(ch==2){
        cout<<"\nEnter total number of processes: ";
        cin>>m;
        for(int i=0;i<m;i++){
            cout<<"\nEnter size: ";
            cin>>val;
            head=bestFit(head,val);
        }
    }
    return 0;
    // 5 15 90 10 40 50 2 2 60 40
}