#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

	key_t key = ftok(".", 'p');
	int id = semget(key, 1, IPC_CREAT | 0600);
	printf("Semget returned: %d\n", id);
	int i = 0;
	int pid;

	semctl(id, 0, SETVAL, 1);

	pid = fork();

	// for(i=0;i<3;i++){

		struct sembuf sb;
		
		sb.sem_num = 0;
		sb.sem_op = -1;
		sb.sem_flg = 0;
		semop(id, &sb, 1);

		printf("Wykorzystanie zasobow przez proces nr %d\n", getpid());
		sleep(50);
		printf("Koniec korzystania z zasobow przez proces nr %d.\n", getpid());

		sb.sem_op = 1;
		semop(id, &sb, 1);

	// }

	if(pid){
		wait(NULL);
		semctl(id, IPC_RMID, 0);
	}
	
	return 0;
}
