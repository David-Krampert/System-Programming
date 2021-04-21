
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int args, char* argv[])
{
  node* head = (node*)malloc(sizeof(node));
  head->next = NULL;

  int id;
  int input = 0;

  while(input != -1)
  {
    printf("\n---------------------------------------------");
    printf("\n(1) Add to the front\n(2) Add to the back\n(3) Remove from the front\n(4) Remove fron the back\n(5) Print list\n(6) To list the number of nodes in list\n(7) Free the list\n(-1) To quit\n");
    printf("---------------------------------------------");
    printf("\nPlease enter a number (from the above list): ");
    printf("\n");
    scanf("%d", &input);
    printf("\n");


    if(input == 1)
    {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	char* name = (char*)malloc(20);


	printf("\nEnter your ID: ");
	scanf("%d", &id);
	printf("\nEnter your name: ");
	scanf("%s", name);

	new_node->id = id;
	new_node->name = name;
	add_front(&head, new_node);
	printf("\nTEST(ID:%d, Name:%s)", head->id, head->name);//test if head is correctly set in main       *(remove when done)

    }
    else if(input == 2)
    {
	node* new_node = (node*)malloc(sizeof(node));
  	new_node->next = NULL;
	char* name = (char*)malloc(20);


	printf("\nEnter your ID: ");
	scanf("%d", &id);
	printf("\nEnter your name: ");
	scanf("%s", name);

	new_node->id = id;
	new_node->name = name;
	add_end(&head, new_node);
	printf("\nTEST(ID: %d, Name:%s)", head->id, head->name);//test if head is correctly sent in main     *(remove when finished)
    }
    else if(input == 3)
    {
	node* removed = rem_front(&head);
	printf("ID: %d, Name: %s\n", removed->id, removed->name);
    }
    else if(input == 4)
    {
	node* removed = rem_end(&head);
	printf("ID: %d, Namw: %s\n", removed->id, removed->name);
    }
    else if(input == 5)
    {
	print_list(head);
    }
    else if(input == 6)
    {
	int num = list_len(head);
	printf("The number of nodes in the list is:%d ", num);
    }
    else if(input == 7)
    {
	free_list(&head);
	printf("\nThe list is now free");
    }
    else if(input == -1)
    {
	printf("\nProgram ended");
    	break;
    }
    else
    {
  	printf("\nPlease enter only numbers from the list!");
    }

  }
  return 0;
}
