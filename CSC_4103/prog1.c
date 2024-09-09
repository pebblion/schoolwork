#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int cmp(const void *p1, const void *p2)
{
  char **sp1 = (char**)p1;
  char **sp2 = (char**)p2;
  char *s1 = *sp1;
  char *s2 = *sp2;
  
  return strcmp(s1, s2);
}

int main(int argc, char *argv[])
{
  int n;
  char buf[BUFSIZE];
  
  printf("Enter n (integer)\n");
  fgets(buf, BUFSIZE, stdin);
  n = atoi(buf);
  printf("%d\n", n);
  
  char **strings = (char**) malloc(n * sizeof(char*));
  
  for(int i = 0; i < n; i++)
  { 
    printf("Enter a string:");
    fgets(buf, BUFSIZE, stdin);
    strings [i] = (char*)malloc(strlen(buf) * sizeof(char));
    strcpy(strings[i], buf);
    // printf("%s\n", strings[i]);
  }

  
  qsort(strings, n, sizeof(char*), cmp);

  for(int i = 0; i < n; i++)
    {
      printf("%s\n", strings[i]);
      free(strings[i]);
    }
  

  free(strings);
  return 0;
}

