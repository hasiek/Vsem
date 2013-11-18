#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	
	pid_t id = 0;
	
	id = fork();
	
	if(id < 0) {
		
		printf("Forking failed.\n");
		exit(1);
	}
	else if(id > 0) {
		
		printf("Killing the parent process.\n");
		exit(0);
	}
	
	umask(0);
	
	pid_t sid = setsid();
	if (sid < 0) {
		
		printf("setsid() failed.\n");
		exit(1);
	}
	
	chdir("/");
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	int i = 0;
	
	while(i < 5) {
		
		sleep(10);
		
	}
	
	return 0;
}
