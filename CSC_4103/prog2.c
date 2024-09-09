#include <stdio.h>

int my_openit(char *name, int prot);
void my_closeit(void);
void f();

typedef struct funcs
{
  int (*openit)(char*, int);
  void (*closeit)(void);
} funcs;

int main(int argc, char *argv[])
{
  funcs z = {.openit = &my_openit, .closeit = &my_closeit};
  f(&z);
  return 0;
}

int my_openit(char *name, int prot)
{
  printf("my_openit called");
  return 0;
}

void my_closeit(void)
{
  printf("my_closeit called");
}

void f(funcs *z)
{

}
