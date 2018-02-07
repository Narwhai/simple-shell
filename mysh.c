#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

//char PATH = "/bin:/usr/bin";
struct command_t {
    char *name;
    int argc;
    char *argv[];
};

const char *prompt = "$";

int main(int argc, char *argv[])
{
    
    struct command_t *command;
    //shell initialization 
	bool shellStatus = true;

    //main loop
    while (shellStatus)
    {					
        //Print prompt string 
		printf("\n%s ", prompt);

        //read and parse command line 

		for (int i = 0; i < argc; i++)
		{
			*command->argv[i] = argv[i];
		}
		*command->name = argv[0];
		command->argc = argc;

		//Find full pathname for file 
		TCHAR full_path[MAX_PATH];
		char *full_pathname = GetFullPathName(_T(*command->argv[1]), MAX_PATH, full_path, NULL);
			//printf("\n%s", *argv[1]);
        //Create a process to execute the command
		system(*command->name);

        //parent waits until child finishes executing command
		if (fork() == 0)
		{
			//this is the child
			//execute in the same environment as parent
			execvp(full_pathname, command->argv, 0);
		}
		else
		{
			//this is the parent -- wait for child to terminate
			wait(status);
		}
    }
	//Shell termination
}//end main