#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	
	pid_t id = 0;
	
	id = fork();

	
	while(1) {
		
		printf("Proces %d\n", getpid());
		sleep(1);
		
	}
	
	return 0;
}
