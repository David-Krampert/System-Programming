// David Krampert
// 02/21/20


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// add a new node to the front of the list
void add_front(node* *head, node* new_node)
{
  new_node->next = *head;
  *head = new_node;
}

// add a new node to the end of the list
void add_end(node* *head, node* new_node)
{
  if((*head)->next == NULL)//empty list
  {
	//new_node->next = NULL;
      //  *head = new_node;
	add_front(head,new_node);
  }
  else
  {
    node* temp = *head;
    while(temp->next != NULL)//loops to the end of the list
    {
  	temp = temp->next;
    }
    temp->next = new_node;//sets new_node to next value after  at the end of list
    new_node->next = NULL;
  }
}


// remove and return the node at the front of the list or NULL if empty
node* rem_front(node* *head)
{
  node* removed = *head;//node to be removed
  *head = (*head)->next;
  return removed;
}

// remove and return the node at the end of the list or NULL if empty
node* rem_end(node* *head)
{
  if(*head == NULL)
	return NULL;

  node* removed = *head;
  node* lag;
  while(removed->next != NULL)
  {
	lag = removed;
	removed = removed->next;
  }
  lag->next = NULL;
  return removed;
}


// return the number of nodes in the list
int list_len(const node* head)
{
  int count = 0;
  while(head)
  {
	head = head->next;
	count++;
  }
return count;
}

// print the data values of  all the nodes in the list (from start to end)
void print_list(const node* head)
{
  node* temp = head;
  if(head == NULL)
	return;
  do{
	printf("ID: %d, Name: %s\n", head->id, head->name);
	head = head->next;
  }while(head);
}


// free the entire list and set *head = NULL
void free_list(node* *head)
{
  node* temp = *head;
  while(temp)
  {
	node* temp_2 = temp;
	free(temp_2->name);
	free(temp_2);
	temp = temp->next;
  }
  *head = NULL;
}

