This is a very basic implementation of linux shell

Build Instructions:
	The makefile is ready, just run the command "make"
	then run "./shell" (without quotation marks!)
	
The following features have been incorporated into the program:

	1> builtin commands : i->echo ii->exit iii->cd iv->pwd
	2> execvp syscall helps to use all the coreutils commands with proper arguements
	3> semi-colon separated list of commands
	4> running program in  background with working bonus 1
	5> relative path applicable when working under home, absolute path everywhere
	6> proper error reporting
	7> modular structure
	8> executing cd without any arguements changes directory to home

