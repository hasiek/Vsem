#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>

#define KEY 1234

typedef struct {
	
	int liczba;
	char znak;
} Wspoldzielona;

Wspoldzielona *wspol;

int main() {
	
	int shmid, semid;
	shmid = shmget(KEY, sizeof(wspol), IPC_CREAT | 0666);
	wspol = shmat(shmid, NULL, 0);
	wspol->liczba = 0;
	wspol->znak = 'a';
	
	semid = semget(KEY, 2, IPC_CREAT | 0600);
	semctl(semid, 0, SETVAL, (int)0);
	semctl(semid, 1, SETVAL, (int)0);
	
	struct sembuf sb;
	
	if(fork() == 0) {
		sb.sem_num = 0;
		sb.sem_op = -1;
		sb.sem_flg = 0;
		semop(semid, &sb, 0);
		wspol->liczba = (wspol->liczba)++;
		wspol->znak = 'b';
		printf("Proces dziecko, element liczba: %d, element znak: %c.\n", wspol->liczba, wspol->znak);
		sb.sem_num = 1;
		sb.sem_op = 1;
		sb.sem_flg = 0;
		semop(semid, &sb, 1);
	}
	sb.sem_num = 1;
	sb.sem_op = -1;
	sb.sem_flg = 0;
	semop(semid, &sb, 1);
	wspol->liczba = (wspol->liczba)++;
	wspol->znak = 'c';
	printf("Proces rodzic, element liczba: %d, element znak: %c.\n", wspol->liczba, wspol->znak);
	sb.sem_num = 0;
	sb.sem_op = 1;
	sb.sem_flg = 0;
	semop(semid, &sb, 0);
    exit(0);
	
	return 0;
}
