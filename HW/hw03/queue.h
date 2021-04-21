#ifndef h
#define h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.c"


int que_size;	//size of queue
int front;	//front of queue
int tail;	//tail of queue
float *queue;	//to point to the queue array of floats


float* create_queue();


void enqueue(float new_value);	//adding to the queue


float dequeue();		//returns a float(the value being removed)


void doubleCapacity(float* *queue, const int cur_size);//double array size


int isFull();		//checks if queue is full


int isHalfFull();	//checks if queue is half full


int isEmpty();		//checks if queue is empty


void halfCapacity(float* *queue, const int cur_size);//shrink array size by half

#endif
