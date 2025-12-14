#include <stdio.h>
#include <string.h>


#define MAX_LINE_COLUMNS 80
#define MAX_ARGS 10

void run_shell()
{
    char input[MAX_LINE_COLUMNS];
    char *argv[MAX_ARGS];
    char *token[];

    for (;;)    
    {
        printf("myshell>  ");
        fgets(input, MAX_LINE_COLUMNS, stdin);
        //printf("Executing %s\n", input);


        // tokenization
        token = strtok(input, " \t\n");
        printf("token: %s\n", token);

        int i = 0;

        while(token != NULL) {
            argv[i] = token;
            //printf("argv[%d]: %s\n", i, token);
            token = strtok(NULL, " \t\n");
            i++;
        }

        // no commands
        if (argv[0] == NULL)  {
            continue;
        }

        // execute a command
        if (strcmp(argv[0], "quit") == 0) {
            return;
        }
        else if (strcmp(argv[0], "cd"))    {
            // change current directory using 'chdir()'
        }
        else if (strcmp(argv[0], "pwd"))    {
            // printf current directory using 'getcwd()'
        }
    }
}

int main(void)
{
    run_shell();

    return 0;
}