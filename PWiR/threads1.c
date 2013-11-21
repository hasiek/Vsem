#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

typedef struct {
	int argument;
	int num1;
	int num2;
} arg;

arg arg1;

void* func1(void* stru) {
	arg* struktura = (arg*) stru;
	printf ("Watek 0 - suma\n");
	return struktura->num1+struktura->num2;
}

void* func2(void* stru) {
	arg* struktura = (arg*) stru;
	printf ("Watek 1 - roznica\n");
	return struktura->num1-struktura->num2;
}

int main() {
	
	pthread_t thread1, thread2;
	int i = 0;
	int wynik = 0;
	arg1.num1 = 33;
	arg1.num2 = 15;
	arg1.argument = 0;
	
	if(pthread_create(&thread1, NULL, func1, &arg1) != 0) {
		printf ("pthread_create() for thread1 error\n");
		exit(EXIT_FAILURE);
	}
	
	arg1.argument = 1;
	if(pthread_create(&thread2, NULL, func2, &arg1) != 0) {
		printf ("pthread_create() for thread2 error\n");
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread1, (void*) &wynik);
	printf ("Wynik dzialania watku 1: %d\n", wynik);
	pthread_join(thread2, (void*) &wynik);
	printf ("Wynik dzialania watku 2: %d\n", wynik);
	
	return 0;
}
