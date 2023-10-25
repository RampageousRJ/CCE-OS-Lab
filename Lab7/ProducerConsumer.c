#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

int cap;
int *Q;
int n;
sem_t full, empty;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(){
    int in = 0;
    for ( int i=0; i<n; i++ ){
        sem_wait(&empty);  //Wait for post on empty
        pthread_mutex_lock( &mutex );
        Q[in] = i+1;
        in = (in+1)%cap;
        printf("P%d Produced -> ", i+1);
        pthread_mutex_unlock( &mutex );
        sem_post( &full );  //Signal full
    }
}
void *consumer(){
    int out = 0;
    for ( int i=0; i<n; i++ ){
        sem_wait(&full);  //Wait for post on full
        pthread_mutex_lock( &mutex );
        printf("P%i Consumed -> ", Q[out]);
        out= (out+1)%cap;
        pthread_mutex_unlock( &mutex );
        sem_post(&empty);  //Signal empty
    }
}
int main(){
    printf("Buffer Size: ");
    scanf("%d", &cap);
    printf("Number of Required Items: ");
    scanf("%d", &n);
    Q = malloc((cap) *sizeof(int));

    pthread_t T[2];
    sem_init( &full, 0, 0 );
    sem_init( &empty, 0, cap);
    pthread_create( &T[0], 0, producer, 0 );
    pthread_create( &T[1], 0, consumer, 0 );
    pthread_join( T[0], 0 );
    pthread_join( T[1], 0 );
    sem_destroy( &full );
    sem_destroy( &empty );
}