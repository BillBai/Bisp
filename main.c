#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <string.h>

static char buffer[2048];

char* readline(char* promt)
{
    fputs(promt);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

// Fake add_history for _WIN32
void add_history(char *input) {}

#else

#include <readline/readline.h>
#include <readline/history.h>

#endif


int main(int argc, char** argv)
{
   puts("Bisp version 0.0.0.1");
   puts("Press ctrl-c to exit\n");

   while (1) {
       char *input = readline("Bisp :> ");

       add_history(input);

       printf("You are %s\n", input);

       free(input);
   }
}

