#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
  
  pid_t process_id = 0;
  pid_t sid = 0;
  
  process_id = fork();
  
  if (process_id < 0) {
    
    printf("Forking failed.\n");
    exit(1);
   
  }
  
  if (process_id > 0) {
    
    printf("Parent process will be killed.\n");
    exit(0);
    
  }
  
  umask(0);
  sid = setsid();
  
  if (sid < 0)
    exit(1);
  
  chdir("/");
  
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  while(1) {
	  
	  sleep(1);
	  
  }
  
  return 0;
  
}
