#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void utworz_procesy(int liczba_procesow);

int main() {
	
	printf("Początek\n");
	utworz_procesy(1);
	printf("Koniec\n");
	sleep(4);
	
	return 0;
}

void utworz_procesy(int liczba_procesow) {
	
	if(liczba_procesow > 1) {
		int i = 0;
		pid_t id = 666;
		while (i <= liczba_procesow-2) {
			i++;
			if(i == 1 || id == 0)
				id = fork();
		}
	}
	
};
