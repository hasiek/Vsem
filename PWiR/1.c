#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[5];
int napisano = 0;
pthread_mutex_t lock;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

char tekst[50];

void* czytelnik() {

	pthread_mutex_lock(&lock);
	pthread_cond_signal(&cond);
	
		while(napisano != 0) {
			
			pthread_cond_wait(&cond, &lock);
			
		}

			printf("Watek czytelnika, wprowadz tekst.\n");
			scanf("%s", tekst);
			napisano = 1;


	
	pthread_mutex_unlock(&lock);
		
	return NULL;
}

void* pisarz() {
	
	pthread_mutex_lock(&lock);
	pthread_cond_signal(&cond);
	
		while(napisano != 1) {
			pthread_cond_wait(&cond, &lock);
		}
			
			printf("Watek pisarza, wpisano tekst:\n");
			printf("%s\n", tekst);
			napisano = 0;
	
	pthread_mutex_unlock(&lock);
	
	return NULL;
}

int main() {
	
		int err;
		
		 if (pthread_mutex_init(&lock, NULL) != 0) {
			 
				printf("\n mutex init failed\n");
				return 1;
		}
	
		err = pthread_create(&(tid[0]), NULL, &czytelnik, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        
        
        
        err = pthread_create(&(tid[1]), NULL, &czytelnik, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        
        //pthread_cond_signal(&cond);
            
        err = pthread_create(&(tid[2]), NULL, &czytelnik, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
        //pthread_cond_signal(&cond);
            
        err = pthread_create(&(tid[3]), NULL, &pisarz, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
        //pthread_cond_signal(&cond);
            
        err = pthread_create(&(tid[4]), NULL, &pisarz, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
        //pthread_cond_signal(&cond);
        
        err = pthread_create(&(tid[5]), NULL, &pisarz, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        
        pthread_join(tid[0], NULL);
		pthread_join(tid[1], NULL);
		pthread_join(tid[2], NULL);
		pthread_join(tid[3], NULL);
		pthread_join(tid[4], NULL);
		pthread_join(tid[5], NULL);
		pthread_mutex_destroy(&lock);
	
		return 0;
}
