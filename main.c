#include<fun.h>
int main(){
	int stats=1;
	while(stats){
		struct utsname unameData;
		uname(&unameData);
		char * currentDir = getcwd(NULL, 0);
		char homePath[1000];
		sprintf (homePath, "/home/%s",getenv("USER"));
		int offSetCurr=0;
		if(strstr(currentDir,homePath)!=NULL){
			offSetCurr=strlen(homePath)-1;
			currentDir[offSetCurr]='~';
		}//print the Display
		printf("<%s@%s:%s>",getenv("USER"),unameData.nodename,currentDir+offSetCurr);
		//function call to read line and execute thereafter
		stats=read_line_shell();
		//carefully free all the allocated variables
		free(currentDir);
	}
	return 0;
}
