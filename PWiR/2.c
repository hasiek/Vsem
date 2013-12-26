#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[10];
pthread_barrier_t bariera;
int licznik = 4;

void* func1() {
	
	printf("Watek A\n");
	pthread_barrier_wait(&bariera);
	printf("Watek B\n");
	return NULL;
}

int main() {
	
	int err;
	
	pthread_barrier_init(&bariera, NULL, licznik);
	
	err = pthread_create(&(tid[0]), NULL, &func1, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
    err = pthread_create(&(tid[1]), NULL, &func1, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
    
    err = pthread_create(&(tid[2]), NULL, &func1, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
    err = pthread_create(&(tid[3]), NULL, &func1, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
	
	
	return 0;
}
