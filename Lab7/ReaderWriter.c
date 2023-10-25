#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t db, mutex;
int rc = 0;

void *writer(void * a){
    int op = (int)a;
    sem_wait(&db);
    printf("W%d -> ",op);
    sem_post(&db);
}

void *reader(void * a){
    int op = (int) a;
    sem_wait(&mutex);
    rc++;
    if(rc == 1)
        sem_wait(&db);
    sem_post(&mutex);
    sem_wait(&mutex);
    rc--;
    if (rc == 0)
        sem_post(&db);
    printf("R%d -> ",op);
    sem_post(&mutex);
}

int main(){
    int r, w;
    printf("Total Reader and Writer: ");
    scanf("%d %d", &r, &w);
    pthread_t op_read[r], op_write[w];
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
    int i=0;
    while(i<r||i<w){
        if(i<r)
            pthread_create(&op_read[i], NULL, reader,(void *)i+1);
        if(i<w)
            pthread_create(&op_write[i], NULL, writer,(void *)i+1);
        i++;
    }
    i=0;
    while(i<r || i<w){
        if(i<r)
            pthread_join(op_read[i], NULL);    
        if(i<w)
            pthread_join(op_write[i], NULL);
        i++; 
    }
    sem_destroy(&mutex);
    sem_destroy(&db);
    return 0;
}