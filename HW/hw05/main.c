#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int args, char* argv[])
{
   node* head = (node*)malloc(sizeof(node));
   head->next = NULL;
   int id;
   int input = 0;

   while(input != -1) {
    printf("\n---------------------------------------------");
    printf("\n(1) Add to the front\n(2) Add to the back\n(3) Add in order\n(4) Remove in order\n(5) Remove from the front\n(6) Remove fron the back\n(7) Print list\n(8) To list the number of nodes in list\n(9) Free the list\n(-1) To quit\n");
    printf("---------------------------------------------");
    printf("\nPlease enter a number (from the above list): ");
    printf("\n"); scanf("%d", &input);
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
        add_end(&head,new_node); 
    }
    else if(input == 3) 
    {
        node* new_node = 
 	(node*)malloc(sizeof(node));
	new_node->next = NULL;
        char* name =(char*)malloc(sizeof(char) * 20);
        printf("\nEnter your id: "); 
        scanf("%d", &id);
        printf("\nEnter your name: ");
      	scanf("%s", name);
        new_node->id = id;
        new_node->name = name; 
      	add_inorder(&head, new_node);
    }
    else if(input == 4) 
    {
        char* key_name = (char*)malloc(sizeof(char)* 20);
        printf("\nEnter a name you want to remove: "); 
	scanf("%s", key_name);
        node* removed = rem_inorder(&head, key_name);

        if(removed != NULL)
	        printf("\nRemoved id: %d name: %s\n", removed->id, removed->name);

	else
                printf("\nNo such element exists in the list");
    }
    else if(input == 6)
    {
        node* removed = rem_end(&head);
        printf("ID: %d, Name: %s\n", removed->id, removed->name);
    }
    else if(input == 7)
    {
        print_list(head);
    }
    else if(input == 8) 
    {
        int num = list_len(head);
        printf("The number of nodes in the list is:%d ", num);
    }
    else if(input == 9)
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
