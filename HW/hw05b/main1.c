#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_input_str (1024)//define the size of the array

typedef struct data
{
  char* name;
  int list_len;
  float* value_list;
}data;

void write_file(data rList[], int i);
void free_memory(data rList[], int i);
void dis_file();
void read_file(data rList[], int i);
 //Declare variables
  struct data *data_record;
  char buff[MAX_input_str];
  char *temp_name;
  int temp_len;
  char *token;
  char *temp_value_list;
  data *temp_data_record;


int main(int args, char* argv[])
{
  int i = 0;
  //call functions
  read_file(data_record, i);
  write_file(data_record, i);
  dis_file();
  free_memory(data_record, i);

}
void read_file(data rList, int i)//how can this be a type conflict when they are both void?
{
  int j=0;
  char * read_result = fgets;

  //read the file
  FILE *fin;
  fin = fopen("input.txt", "r");

  while(fgets( buff, MAX_input_str, (FILE*)fin ) != NULL)
  {
    if( read_result != NULL)
    {
        j=0;

        //Initially assign blank or NULL data members of structure
        temp_name = buff;
        temp_len = atoi(strtok(buff, "~"));
        temp_value_list = strtok(NULL, "~");

        //Allocate dynamic memory to name or value_list members of structure.
        data_record[i].name = (char*)malloc(strlen(temp_name) * sizeof(char));
        int list_len = strlen(temp_name);								   //What is this ****!!!!!!
        data_record[i].value_list = (float*)malloc(temp_len * sizeof(float));
        data_record[i].list_len = temp_len;

        //read the ontents of the file.
        token = temp_value_list;
        while((token != NULL) && j<temp_len)
        {
          data_record[i].value_list[j++] = atof(token);
          token = strtok(NULL,"~");
        }

        //copy the data of temp to records
        strcpy(data_record[i].name , temp_name);
        i++;

    }

  }

//  i--;    <- not sure if this is needed**


  //close the file
  fclose(fin);
  return i;
}


void write_file(data *rList, int i)
{
  //char* string = (char*)malloc(sizeof(char)* 100);

  //data* arry = (data*)malloc(sizeof(data)* 1024);

  int j = 0;//counter for each data entry
  int k = 0;//counter for the data in the entry

  FILE *fout;
  fout = fopen("output.txtt", "w");

  while(j<i)
  {
        fprintf(fin, "%s; %d:", rList[j].name, rList[j].list_len);

        for(k=0; k<rList[j].list_len-1; k++)
        {
          fprintf(fin, "%f", rList[j].value_list[k]);
        }

        fprintf(fin, "%f\n", rList[j].value_list[k]);
        j++;
  }
}

void free_memory(data *rList, int i)
{
  int j = 0;

  while(j<i)
  {
    free(rList[j].name);
    free(rList[j].value_list);
    j++;
  }
}

void dis_file()
{
  char buff[MAX_input_str];

  fout = fopen("output.txt", "r");//opens the file

  while(fgets(buff, MAX, fin) != NULL)
  {
    printf("%s\n", buff);
  }
  fclose(fin);
}


