#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/wait.h>

int main() {
	
	key_t key = ftok(".", 'p');
	int id = semget(key, 1, IPC_CREAT | 0600);
	int i;
	pid_t pid;
	
	printf("semget() returned %d\n", id);
	
	semctl(id, 0, SETVAL, 1);
	
	pid = fork();
	
	for (i = 0; i < 2; i++) {
	
		struct sembuf buf;
		buf.sem_num = 0;
		buf.sem_op = -1;
		buf.sem_flg = 0;
		
		semop(id, &buf, 1);
		
		printf("Wykorzystanie zasobów przez proces nr %d.\n", getpid());
		sleep(10);
		printf("Proces %d zwalnia zasoby.\n", getpid());
		
		buf.sem_op = 1;
		semop(id, &buf, 1);
	}
	
	if(pid)
		semctl(id, IPC_RMID, 0);
		
	return 0;
}
