#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid_t sid;
	FILE *fp=NULL;
	
	pid=fork();
	
	if(pid<0)
	{
		printf("Fork fails");
	}
	if(pid>0)
	{
		printf("PID of child is : %d\n",pid);
		exit(0);
	}
	
	umask(0);
	
	sid=setsid();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	fp=fopen("Vishal.txt","w+");
	if(fp==NULL)
	{
		printf("Unable to create file\n");	
	}
	
	while(1)
	{
		sleep(2);
		fprintf(fp,"Process is runnning\n");
		fflush(fp);
	}	
	
	fclose(fp);
	
	return 0;
}
