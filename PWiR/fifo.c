#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[5];
int counter;
pthread_mutex_t lock;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
	int tablica[10];
	int* glowa;
	int* ogon;
	int liczba_elementow;
} fifo;

fifo kolejka;

void* pisz()
{
    pthread_mutex_lock(&lock);
    
    do {
		
		if(kolejka.ogon != &kolejka.tablica[9]) {
			printf("Probuje pisac do tablicy\n");
			
			kolejka.liczba_elementow += 1;
			kolejka.ogon += 1;
			*kolejka.glowa = kolejka.liczba_elementow;
			
			printf("Napisano: %d, opuszczam sekcje\n", *kolejka.glowa);
			break;
		}
		else 
			pthread_cond_wait(&cond, &lock);
	} while (0);

    pthread_mutex_unlock(&lock);

    return NULL;
}

void* usun()
{
    pthread_mutex_lock(&lock);
	do {
		if (&kolejka.ogon != &kolejka.glowa) {
			printf("Usuwam element z kolejki\n");
			kolejka.liczba_elementow -= 1;
			kolejka.ogon -= 1;
			printf("Element usuniety, opuszczam sekcje\n");
			break;
		}
		else
			pthread_cond_wait(&cond, &lock);
	} while (0);
    pthread_mutex_unlock(&lock);

    return NULL;
}
int main(void)
{
    int err;
    int i;
    printf("Wypelniam tablice zerami\n");
    for(i = 0; i < 10; i++) {
		kolejka.tablica[i] = 0;
	}
	printf("Ustawiam glowe\n");
    kolejka.glowa = &kolejka.tablica[0];
    printf("Ustawiam ogon\n");
	kolejka.ogon = &kolejka.tablica[0];
	printf("Ustawiam liczbe elementow\n");
	kolejka.liczba_elementow = 0;
   

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

		err = pthread_create(&(tid[0]), NULL, &usun, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        
        pthread_cond_signal(&cond);
        
        err = pthread_create(&(tid[1]), NULL, &pisz, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        
        pthread_cond_signal(&cond);
            
        err = pthread_create(&(tid[2]), NULL, &usun, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
        pthread_cond_signal(&cond);
            
        err = pthread_create(&(tid[3]), NULL, &pisz, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
        pthread_cond_signal(&cond);
            
        err = pthread_create(&(tid[4]), NULL, &pisz, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
            
        pthread_cond_signal(&cond);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
