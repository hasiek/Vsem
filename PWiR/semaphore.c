#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY 123
#define MAX 10


int main()
{
    int i, j, shmid, semid, *buf ;
    shmid = shmget(KEY, 5, IPC_CREAT | 0600);
    buf = shmat(shmid, NULL, 0);

    semid = semget(KEY, 2, IPC_CREAT | 0600);
    semctl(semid, 0, SETVAL, (int)0);
    semctl(semid, 1, SETVAL, (int)0);
		struct sembuf sb;
        if(fork() == 0)
        {
            // semid = semget(KEY, 2, 0600);
            // shmid = shmget(KEY, 5, IPC_CREAT | 0600);
            // buf = shmat(shmid, NULL, 0);
            sb.sem_num = 0;
			sb.sem_op = -1;
			sb.sem_flg = 0;
            buf[1] = buf[1]++;
            printf("Potomek: Zmienna wynosi: %d \n",buf[1]);
            sb.sem_num = 1;
			sb.sem_op = 1;
			sb.sem_flg = 0;
			//exit(0);
        }
        //semid = semget(KEY, 2, 0600);
        //shmid = shmget(KEY, 5, IPC_CREAT | 0600);
        //buf = shmat(shmid, NULL, 0);
        sb.sem_num = 1;
		sb.sem_op = -1;
		sb.sem_flg = 0;
        buf[1] = buf[1]++;
        printf("Rodzic: Zmienna wynosi:  %d\n", buf[1]);
        sb.sem_num = 0;
		sb.sem_op = 1;
		sb.sem_flg = 0;
        exit(0);    


        //wait(15);
	return 0;
}
