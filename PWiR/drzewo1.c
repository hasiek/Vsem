#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	
	pid_t p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
	
	p1 = fork(); 
	
	if(p1 == 0) {
		
		p5 = fork();
		if (p5 == 0)
			sleep(15);
		else
			sleep(15);
	}
	else {
		
		p3 = fork();
		if(p3 == 0) {
			
			p6 = fork();
			if(p6 == 0)
				sleep(15);
			else {
				
				p7 = fork();
				if (p7 == 0)
					sleep(15);
				else
					sleep(15);
			}
			
		}
		else {
			
			p4 = fork();
			if(p4 == 0) {
				
				p8 = fork();
				if(p8 == 0)
					sleep(15);
				else {
					
					p9 = fork();
					if(p9 == 0)
						sleep(15);
					else {
						
						p10 = fork();
						if(p10 == 0)
							sleep(15);
						else
							sleep(15);
					}
					
				}
				
			}
		}
		
	}
	
	sleep(50);
	return 0;
}
