#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

int main(void) 
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	printf("start? : %ld\n", start.tv_sec);
	if (usleep(1000000) != 0)//it correspond to 1 sec
	{
		printf("not working \n");
		return (0);
	}
	gettimeofday(&end, NULL);
	printf("end? : %ld\n", end.tv_sec);
	printf("diff? : %ld\n", end.tv_sec - start.tv_sec);
	return (0);
}
