#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

void swap(char a1[100],char a2[100])
{
    char temp[100];
    strcpy(temp,a1);
    strcpy(a1,a2);
    strcpy(a2,temp);
}

int main()
{
    char str[100][100];

    printf("Total number of strings required: ");
    int i,j,n,x;
    scanf("%d",&n);

    printf("Input Strings: ");
    for(int i = 0 ; i < n ; i++) {
      scanf("%s", str[i]);
    }
    
    pid_t p1 = fork();
    
    if(p1 == 0) {
       
       int pos,max;

        printf("\nChild Process 1 ~ Selection Sort: ");
         
        for(i = 0 ; i < n ; i++) { 
            
            pos=i,max=0;
            for(j=i;j<n;j++) {

                if(x = strcmp(str[i],str[j]) > max) {
                    max=x;
                    pos=j;
                }
            }
            
            swap(str[i],str[pos]);
        }
              
        
       for(i = 0 ; i < n ; i++) {
            printf("%s ",str[i]);
        }
        printf("\n\n");
        exit(0);    

    }
    else {
      
      wait(&i);
      pid_t p2 = fork();
      
      if(p2 == 0) {
         
        printf("Child Process 2 ~ Bubble Sort: ");
       
        for(i=0;i<n;i++) {
            for(j=0;j<n-i-1;j++) {
                if(strcmp(str[j],str[j+1])>0) {
                    swap(str[j],str[j+1]);
                }
            }
       }

       for(i = 0 ; i < n ; i++) {
            printf("%s ",str[i]);
        }
        printf("\n\n");
    
    } 
        else {

        wait(&i);
        printf("Unsorted: ");
        for(i=0;i<n;i++) {
            printf("%s ",str[i]);
        }
        printf("\n\n");
    
        wait(&i);
    }

}

    return 0;
}