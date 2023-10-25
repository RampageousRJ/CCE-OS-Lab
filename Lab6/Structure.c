#include <stdio.h>

typedef struct{
    int a;
    int b;
}ABC;

int main(){
    int n;
    printf("Enter size of array of struct: ");
    scanf("%d",&n);
    ABC* arr = (ABC*) malloc(n+1*sizeof(ABC));
    for(int i=0;i<5;i++){
        arr[i].a=i+1;
    }
    printf("Value of array: ");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i].a);
    }
    return 0;
}