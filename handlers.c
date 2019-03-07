/*
 * Ali Inan
 * CSO Proj4
 * 
 */

#include "shell.h"

void sigintHandler(int sig_num){
	return;
}


void sigchildHandler(int sig_num){
	pid_t pid=-1;
	int status; 
	
	while (waitpid(pid,&status,WNOHANG) > 0){};
}

int main()
{
	if (signal(SIGCHLD, sigchildHandler) == SIG_ERR){
		perror("Signal error:");
		exit(1);
	}
		
	if (signal(SIGINT, sigintHandler) == SIG_ERR){
		perror("Signal error:");
		exit(1);
	}
	
    while (userinput(  ) != EOF ) {
        procline();
    }
    return 0;
}
