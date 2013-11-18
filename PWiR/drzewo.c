#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	
	pid_t p1, p2, p3, p5;
	
	p1 = fork();
	
	switch(p1) {
		
		case(0): 
			// kod procesu p2 - dziecka procesu p1
			p2 = fork();
			switch(p2) {
				
				case(0):
					//kod procesu p4 - dziecka procesu p2
					sleep(50);
					break;
				default:
					// kod procesu p2 jako rodzica procesu p4
					sleep(50);
					break;	
			}
		default:
			// kod procesu p1
			p3 = fork();
			switch(p3) {
				
				case(0):
					// kod procesu p3 - dziecka procesu p1
					p5 = fork();
					switch(p5) {
						
						case(0):
							// kod procesu p5 - dziecka procesu p3
							sleep(50);
							break;
						default:
							// kod procesu p3 jako rodzica procesu p5
							sleep(50);
							break;
						}
						break;
						
				default:
						// kod procesu p1
						sleep(50);
						break;
				}
				
			}
	sleep(50);
	return 0;
}
