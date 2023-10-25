#include <stdlib.h>
#include <stdio.h>

void firstFit(int *size,int val,int n){
    for(int i=0;i<n;i++){
        if(size[i] >= val){
            printf("Process can be fitted into hole of size %d",size[i]);
            size[i]-=val;
            return;
        }
    }
    printf("Process cannot be fitted...");
}

void bestFit(int *size,int val,int n){
    int small=999,pos=-1;
    for(int i=0;i<n;i++){
        if(val <= size[i] && size[i] < small){
            small=size[i];
            pos=i;
        }
    }
    if(small!=999){
        printf("Process can be fitted into hole of size %d",small);
        size[pos]-=val;
        return;
    }
    printf("Process cannot be fitted");
}

void main(){
    int n,val,m,ch;
    printf("Enter total number of holes: ");
    scanf("%d",&n);
    printf("\nEnter sizes of holes: ");
    int *size = (int *)malloc((n*sizeof(int)));
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        size[i]=val;
    }
    printf("\n\nMENU\n1.First Fit\n2.Best Fit\nEnter your choice: ");
    scanf("%d",&ch);
    if(ch==1){
        printf("\nEnter total number of processes: ");
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            printf("\nEnter size: ");
            scanf("%d",&val);
            firstFit(size,val,n);
        }
    }
    else if(ch==2){
        printf("\nEnter total number of processes: ");
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            printf("\nEnter size: ");
            scanf("%d",&val);
            bestFit(size,val,n);
        }
    }
    // 5 15 90 10 40 50 1 3 60 40 60
}