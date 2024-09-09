#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if(argv[1] == NULL)
    {
      printf("No argument given\n");
    }

  char string[100];
  FILE *fptr = fopen(argv[1], "r");
  
  fgets(string, 100, fptr);
  printf("%s\n", string);
  return 0;
}
