#include <stdio.h>

static char input[2048];

int main(int argc, char** argv)
{
   puts("Bisp version 0.0.0.1");
   puts("Press ctrl-c to exit\n");

   while (1) {
       fputs("bisp :> ", stdout);

       fgets(input, 20048, stdin);

       printf("You are %s", input);
   }
}
