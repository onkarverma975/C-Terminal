#include<fun.h>
int read_line_shell()
{
	char *line = NULL;
	ssize_t bufsize = 0;//buffer variable for the getline call
	getline(&line, &bufsize, stdin);
	pid_t pid;
	int status;
	//check for all the processes which have parent as the current process,
	//check their status
	//and relay successful termination if it has exited
	while((pid = waitpid(-1, &status, WNOHANG)) > 0) {
	        printf("process with pid %d exitted normally\n",pid);
	}
	//start tokenizing with ; and \n
	char *init_tok;
	char*end_str;
	init_tok = strtok_r(line, ";\n", &end_str);
	while( init_tok != NULL )
	{
		char * end_token;
		int buffersize = 10000, position = 0;//buffersize
		char **tokens = malloc(buffersize * sizeof(char*));//2-D array of characters to pass the tokenized string fragments
		char *token, **tokens_backup;
		char tokenizer[100]=" ";
		token = strtok_r(init_tok, tokenizer, &end_token);
		//now, tokenize using space
		while (token != NULL) {
			tokens[position] = token;
			position++;
			token = strtok_r(NULL, tokenizer, &end_token);
		}
		tokens[position] = NULL;
		int i=0;
		int exeProg=execute_shell(tokens);
		if(exeProg==0){
			return 0;
		}
		init_tok= strtok_r(NULL,";\n", &end_str);
		position=0;
		free(tokens);
	}
	return 1;
}
