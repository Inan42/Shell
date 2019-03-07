/*
 * Ali Inan
 * CSO Proj4
 * 
 */

#include "shell.h"
#include <errno.h>

// execute a command with optional wait
int runcommand(char **cline, int where) {
    pid_t pid;
    int status;
    
    //builtin exit command (Fix Bug 3)
	//if input is 'exit' simply exit shell
    if (strcmp(cline[0], "exit") == 0){
		exit(0);
	}
	
	//builtin cd command using chdir (Fix Bug 2)
	//if input is 'cd' with no paramters
	if (strcmp(cline[0], "cd") == 0 && cline[1] == 0){
		char* home = getenv("HOME");
		int ret = chdir(home);
		if( ret == -1)
			perror(SHELL_NAME);
		return;
	}
	
	//if input is 'cd' with parameter PATHNAME or ..
	else if (strcmp(cline[0], "cd") == 0 && cline[1] != 0){
		int ret = chdir(cline[1]);
		if(ret == -1)
			perror(SHELL_NAME);
		return;
	}

    switch(pid=fork()) {
    case -1:
        perror(SHELL_NAME);
        return (-1);
    case 0:
		//put background process in separate group 
		//so it doesn't receive Ctrl-C signal
		if (where == BACKGROUND){
			setpgid(pid, 0); 
		}
        execvp(*cline,cline);
        //we should never get to this code, sice execve does not return
        perror(*cline);
        exit(1);
    }
    // code for parent
    // if background process print pid and exit
    // program is running in the background
    if(where == BACKGROUND) {
        printf("[Process id %d]\n",pid);
        return (0);
    }
	
    // wait until process pid exits
    if (waitpid(pid,&status,0) == -1)
        return (-1);
    else{
        return (status);
	}
}
