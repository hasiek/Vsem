#include <stdio.h>
#include <unistd.h>

int main() {
	
	pid_t process_id = 0;
	int variable = 5;
	
	process_id = fork();
	
	if (process_id == 0) {
		
		printf("Variable is %d in child process.\n", variable);
		variable *= 3;
		printf("Variable is %d in child process.\n", variable);
		
	}
	else if(process_id > 0) {
		
		printf("Variable is %d in parent process.\n", variable);
		
	}
	
	
	return 0;
}
