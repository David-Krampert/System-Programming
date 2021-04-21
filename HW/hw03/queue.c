#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


int que_size;	//intial capacity 1
int front;
int tail;		//when tail = 0, queue is empty

//float array[1];		//creating queue with a size of 1
//float *queue = array;	//pointer to queue;


float* create_queue()//not sur if this works
{
	queue = (float*)malloc(sizeof(float) * 1);
	que_size = 1;
	return array;
}


void enqueue(float value)
{

  if(isFull() == 1)
  {
        printf("\nThe queue is full. Doubling queue\n");
        doubleCapacity(&queue, que_size);
        *(queue + tail) = value;        //adding the value to the queue
        tail++;                         //increasing the tail
	que_size++;
  }
  else if(isEmpty() == 1)
  {
	front = 0;
	tail = 1;
	*(queue + front) = value;	//adding the value to the queue
	que_size++;
  }
  else
  {
	*(queue + tail) = value;
	tail++;
	que_size++;
  }
}


float dequeue()//returns the float value being removed
{
  float value_returned;

  if(isEmpty() == 1)
  {
	printf("\nThe queue is empty. Nothing to remove\n");
	return -1;
  }
  else
  {
	value_returned = *(queue + tail - 1);//i dont know if i need the -1
	tail--;
	que_size--;

	if(isHalfFull() == 1)
	{
		printf("\nThe queue is less than half full. Shrinking queue\n");
		halfCapacity(&queue, que_size);
	}
  }
  return value_returned;
}


int isEmpty()	//checks if queue is empty
{
  if(tail - front == 0)
  {
	return 1;	//queue is empty
  }

  return 0;	//queue is NOT empty
}


int isFull()
{
  if(tail - front == que_size)
  {
	return 1;	//the queue is full
  }

  return 0;		//the queue is NOT full
}


int isHalfFull()
{
  if(tail - front < que_size / 2)
  {
	return 1;	//the queue is less than half full
  }
	return 0;	//the queue is NOT less than half full
}


void doubleCapacity(float* *queue, const int cur_size)//test?
{
  float * tmp = (float*)malloc(sizeof(float)*(cur_size * 2));//creates a new array twice as big

  int i;
  for(i = 0; i < cur_size; ++i)
  {	//loops throgh queue and copies values into new queue
	tmp[i] = (*queue)[i];
  }

  free(*queue);//frees old array of values
  *queue = tmp;//assigns pointer of old array to the 2X array
}


void halfCapacity(float* *queue,const int cur_size)
{
  float * tmp = (float *)malloc(sizeof(float)*(cur_size / 2));//creates a new array half the size of the old one

  int i;
  for(i = 0; i < cur_size/2; ++i)//only loops through half of the old array
  {     //loops throgh queue and copies values into new queue
        tmp[i] = (*queue)[i];
  }

  free(*queue);//frees old array of values
  *queue = tmp;//assigns pointer of old array to the 2X array
}

