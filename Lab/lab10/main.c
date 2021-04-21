// David krampert
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int args, char* argv[])
{
  printf("\n");
  int num = 0;

  pid_t pid = fork(); // create child

  // your code goes here ...
  if( pid == 0 ) //child
  {
    printf("I am the child");
    num = num + 2;

    //use execlp to execute command ( pwd ) from shell
    execlp("pwd", "pwd", (char*)0);

    fflush(stdout);//clears buffer
  }
  else if( pid > 0 )// parent
  {
    printf("I am the parent");
    num = num + 4;

    // use execlp to execute command ( ls -l ) from shell
    execlp("ls", "ls", "-l", (char*)0);

    printf("\nEnd parent");// this wont show up

    fflush(stdout);//clears buffer
  }
  else  // pid < 0   --> fork error
  {
    printf("Bad fork()");
    exit(1);
  }

  printf("\npost-fork num = %d\n", num);
  printf("\n");


  return 0;
}

