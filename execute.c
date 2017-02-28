#include<fun.h>
int launch_shell(char **args)
{
	pid_t pid,pid_a,process_id;
	int i=0,isBackground=0;
	//isBackground =1 means blocking
	//isBackground=0 means non-blocking
	while(args[i]!=NULL){
		int j;
		//store the position of '&' if any
		for(j=0;j<strlen(args[i]);j++){
			if(args[i][j]=='&'){
				isBackground=i;
			}
		}
		i++;
	}

	pid = fork();

	if (pid == 0) {
		process_id=getpid();
		// Child process
		char**passing=malloc(10000 * sizeof(char*));
		int pos_arg=0,pos_pass=0;
		//setting the passing arguements for '&'
		while (args[pos_arg] != NULL) {
			if (pos_arg!=isBackground || isBackground==0) {
				passing[pos_pass] = args[pos_arg];
				pos_arg++;
				pos_pass++;
			}
			else{
				pos_arg++;
			}
		}
		passing[pos_pass] = NULL;
		if (execvp(args[0], passing) == -1) {
			fprintf(stderr,"shell: Problem in executing \"%s\"\n",args[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) {
		// Error forking
		perror("shell");
	}
	else {
		// Parent process
		//wait for the child process if background is not required
		if(isBackground==0)
			wait(NULL);
		else{
			printf("process pid %d started for %s\n", pid,args[0]);
		}
	}
	return 1;
}
int execute_shell(char **args)
{
	int i;

	if (args[0] == NULL) {
		perror("shell");
		// An empty command was entered.
		return 1;
	}
	//
	if(strcmp(args[0],"cd")==0)
		return cd_shell(args);
	if(strcmp(args[0],"echo")==0)
		return echo_shell(args);
	if(strcmp(args[0],"pwd")==0)
		return pwd_shell(args);
	if(strcmp(args[0],"exit")==0)
		return exit_shell(args);
	//if(strcmp(args[0],"pinfo")==0)
	//	return pid(args[1]);
	return launch_shell(args);
}
