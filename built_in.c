#include<fun.h>
char*path_converter(char*inp){
	char home[10000];
	sprintf(home,"/home/%s",getenv("USER"));
	if ((inp == NULL)||(strcmp(inp,"~")==0)) {
		inp=malloc(strlen(home)*sizeof(char));
		strcpy(inp,home);
	}
	else{
		if(strstr(inp,"~")!=NULL){
			strcat(home,inp+1);
			inp=malloc(strlen(inp)*sizeof(char));
			strcpy(inp,home);
		}
	}
	return inp;
}
int cd_shell(char **args)
{
	if (chdir(path_converter(args[1])) != 0) {
		perror("shell");
		//fprintf(stderr, "shell: Error: path \"%s\" does not exit\n",args[1]);
	}
	return 1;
}
int pwd_shell(){
	char * currentDir = getcwd(NULL, 0);
	printf("%s\n",currentDir);
	return 1;
}
int exit_shell(){
	return 0;
}
int echo_shell(char **string){
	int i=1;
	if (string[1] == NULL) {
		fprintf(stderr, "shell: expected argument to \"echo\"\n");
	}
	else {
		while(string[i]!=NULL){
			int len=strlen(string[i]);
			for(int j=0;j<len;j++)
				if(string[i][j]!='"')
					printf("%c",string[i][j]);
			i++;
		}
	}
	return 1;
}
int pid_shell(char*proc){
	printf("pid-->%s\n",proc);
	int dump;
	char procPath[10000], deump[1000];
	//begin
	char name[1024];

	sprintf(procPath,"/proc/%s/stat",proc);
/*
	FILE*fp=fopen(procPath,"r");
	printf("%lld\n",(long long int)fp);
	fscanf(fp,"Name:\t%s\nState:\t%s",deump,name);
	printf("Process Status -- %s\n", name);
	fclose(fp);
*/	//end
	//begin
//	struct rusage r_usage;
//	getrusage(RUSAGE_SELF,&r_usage);
//	char name[10];
//	sprintf(procPath,"/proc/%d/stat",proc);
	//end
	//begin
	sprintf(procPath,"/proc/%s/exe",proc);
	if (readlink(procPath, name, sizeof(name)-1) < 0)
	{
		fprintf(stderr, "readlink");
		return -1;
	}
	printf("Executable Path -- %s\n",name);
	//end
}
