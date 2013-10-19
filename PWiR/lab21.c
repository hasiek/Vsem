#include <stdio.h>
#include <unistd.h>

int main() {
	
	pid_t process_id = 0;
	
	process_id = fork();
	
	while(1) {
	
		if (process_id == 0) {
			
			printf("Child process is %d\n", getpid());
			sleep(1);
			
		}
		else if(process_id > 0) {
			
			printf("Parent process %d\n", getpid());
			sleep(1);
		}
	}
	
	return 0;
}
