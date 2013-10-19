#include <stdio.h>
#include <unistd.h>

int main() {
	
	int p1 = 0, p2 = 0, p4 = 0;
	
	p1 = fork();
	p2 = fork();
	
	if(p1 == 0) {
		
		printf("Process P1\n");
		sleep(1);
		
	}
	else if (p1 > 0) {
		
		printf("Process P2\n");
		p4 = fork();
		if (p4 > 0)
			printf("Process P4\n");
			
	}
	/* if(p2 > 0) {
		
		printf("Process P3\n");
		p4 = fork();
		if (p4 > 0)
			printf ("Process P5\n");
	} */
	
	return 0;
}
