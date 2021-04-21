#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 257

int main(int args, char* argv[])
{
  printf("\n");
  // buffer used for pipe reads and writes
  char buffer[BUFFER_SIZE];

  // create an array of two file descriptors
  // for use with pipe() [0] - read, [1] - write
  int pipe_fds[2];

  // create a pipe - must be done before fork()
  // so that the read and write descriptors are
  // available to both parent and child
  int psts; // holds result of pipe creation attempt
  //  <your code here>;
  psts = pipe(pipe_fds);

  if ( psts == 0 ) // pipe success
  {
    pid_t pid = fork(); // create child process

    if ( pid > 0 ) // parent process
    {
      printf("I am the parent-receiver\n");
      close(pipe_fds[1]); // will not send

      // wait - read message from child when it arrives
      //  <your code here>
      read(pipe_fds[0], buffer, BUFFER_SIZE);
      // echo message to the screen
      //  <your code here>
      printf("I just recieved a message from my child :\n");
      printf("%s\n", buffer);


      read(pipe_fds[0], buffer, BUFFER_SIZE);
      // echo message to the screen
      //  <your code here>
      printf("I just recieved a second message from my child :\n");
      printf("%s\n", buffer);




      close(pipe_fds[0]); // done listening to child
    }
    else if ( pid == 0 ) // child process
    {
      printf("I am the child-sender\n");
      close(pipe_fds[0]); // will not receive

      // create the message "I am alive and doing fine!"
      //  <your code here>
      strcpy(buffer, "I am still alive and doing fine\n");
      // send the message back to parent
      //  <your code here>
      write(pipe_fds[1], buffer, strlen(buffer)+1);

      //clear buffer????
      sleep(1);
      //create second message
      strcpy(buffer, "If you still love me you will send me beer money\n");
      write(pipe_fds[1], buffer, strlen(buffer)+1);

      close(pipe_fds[1]); // done talking back to parent
    }
    else // ( pid == -1 ) ->  fork failed
    {
      printf("Fork Error!\n");
      exit(2);
    }
  }
  else // ( psts == -1 ) -> pipe failed
  {
      printf("Pipe Error!\n");
      exit(1);
  }

  printf("\n");
  return 0;
}

