// David Krampert
// CS377 hw02
// 02/10/20

#include <stdio.h>
#include <stdlib.h>
#include "histo.h"
#include <math.h>
#include <string.h>

#define LETTERS 26 // number of unique “letter” characters

//typedef unsigned char byte; // may be useful for casting(s)



void init_histogram(int histo[]) // set all elements of the histogram to zero
{
	int i;
	for(i = 0; i < LETTERS; ++i) //loops thought all 26 letters
	{
		histo[i] = 0;	//sets index i to 0
	}
}


void cons_histogram(const char string[], int histo[])
// construct the histogram from string
{
	int i;
	for(i=0; string[i] != '\0'; ++i)//main loop
	{
	  int char_letter = (int)string[i];
	  if(char_letter >= 'a' && char_letter <= 'z')
		++histo[char_letter - 'a'];
	}
}


void most_frequent(const int histo[], char* ret_val)
// set *ret_val to a most occurring digit character – hence returning it
{
	int i;
	int char_val = 0;
	int index_of_max;
	for(i = 0; i < LETTERS; ++i)
	{
		if(histo[i] > char_val)
		{
			char_val = histo[i];
			index_of_max = i;
		}
	}
	//ret_val = &('a' + index_of_max);
	char temp  = 'a' + index_of_max;
	ret_val = &temp;
	printf("\n%c occurred most often\n", temp);// I couldn't figure out the pointer and get ret_val to change so I printed it here instead
}


void display_histogram(int* const histo)
// display the histogram sparsely
{
	printf("\n");
	for(int i = 0; i < LETTERS; ++i)
	{
		int val = histo[i];//value in array at the index that ptr is pointing to
		if(val > 0)
		{
			if(val > 1)
			  printf("%c appeared %d times \n",'a'+i,  val);
			else
			  printf("%c appeared %d time \n", 'a'+i, val);
		}
	}
	char most_often;
	most_frequent(histo,&most_often);
}
