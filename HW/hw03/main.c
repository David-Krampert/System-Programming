#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


int main(int args, char* argv[])//testing method..
{

  int que_size = 1;
  int front = 0;
  int tail = 0;
  float *queue = create_queue;

  int c=0;

  while(c!=3)
  {

      printf("1:Enqueue\n2:Dequeue\n3:Exit\nEnter ur choice:");
      scanf("%d",&c);
      if(c==1)
      {
          printf("Enter a float :");
          scanf("%f",&queue);
          enqueue(queue);

      }
      else if(c==2)
      {
          printf("Element dequeued :%f\n",dequeue(queue));
      }
      else if(c==3)
      {
          break;//breaking loop
      }
      else
      {
          printf("Enter again:");
      }

  }
  return 0;
}



/*

int main(int args, char* argv[])
{
  const float SIZE = 1;
  int* my_queue = NULL;
  float* que_tail;

  my_queue = create_queue(SIZE, &que_tail);

  free(my_queue);

  return 0;
}
*/

//  int i;
//  for(i = 1; i < 10; ++i)
//    add(my_queue, &que_tail, SIZE, 2 * i);
//  printf("tail = %d\n", que_tail);

//  for(i = 1; i < 10; ++i)
//    printf("%d\n", rem(my_stack, &my_top));
//  printf("top = %d\n", my_top);

//  free(my_stack);

//  return 0;





