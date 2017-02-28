#ifndef __FUN_DEX_H__
#define __FUN_DEX_H__
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/utsname.h>
#include <sys/types.h>
#include <sys/wait.h>
char*path_converter(char*inp);
int cd_shell(char **args);
int pwd_shell();
int exit_shell();
int echo_shell(char **string);
int pid_shell(char*proc);
int launch_shell(char **args);
int execute_shell(char **args);
int read_line_shell();
#endif
