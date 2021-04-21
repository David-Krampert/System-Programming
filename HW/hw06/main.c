//David Krampert
//
//		**when calling main use ./main testDir**
//
//
/////////////////////////////////////////////////////////////////////////////////

// Includes ---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////////////////////

// Define functions -------------------------------------------------------------

//Gets the directory to search through
void getDirectory(int args, char* argv[]);
//Searches through given directory and finds regular files of at least mSize
int searchDirectory(DIR* searchD, char* argv[], int mSize);
/////////////////////////////////////////////////////////////////////////////////

// Functions --------------------------------------------------------------------

// main function
int main(int args, char* argv[])
{
  getDirectory(args,  argv);
  return 0;
}


// getDirectory
void getDirectory(int args, char* argv[])
{
  //delcare variables
  int mSize = 1024;// minimum size of the file
  int number_of_files; //holds number of regular files found in searchDirectory

  //if args = 0 there are no directories to look through
  if(args > 0)
  {
    //change directory to (testDir)
    int changeDir = chdir( strdup(argv[1]) );

    //gets the first directory from args at index 1
    DIR *searchD;
    searchD = opendir( "." );

    if( searchD == NULL)//if there is no directory to open exit
    {
      printf("Directory could not be opened");
      exit(1);
    }
    else
    {
      //call second function to read through the directory and return the number of regular files
      number_of_files = searchDirectory(searchD, argv, mSize);

      //after searchDirectory prints the regular files and their sizes
      //print off number_of_files (number of regular files)
      printf("\n%d Matching files in all\n", number_of_files);
    }

    //change the directory back to hw06 (where the .c and makefile are stored)
    changeDir = chdir("..");
  }
  else
  {
    printf("ERROR args was equal to zero");
  }
}


//searchDirectory
int searchDirectory(DIR* searchD,char* argv[], int mSize)
{
  int number_of_files_in_dir = 0;//holds the number of regular files

  struct dirent* dentry; // a pointer to and "internal" structure

  //get the "first" entery, no allocation needed - unless we need to save each one
  dentry = readdir(searchD);//read through the searchD directory

  struct stat file_stat; //holds file stats


  while(dentry != NULL) // while the directory dentry is vaild, use it
  {

    //get stats
    if( !stat(dentry->d_name, &file_stat) ) //if stat was sucessful
    {
      //find the regular files
      if( S_ISREG(file_stat.st_mode) ) //regular file
      {
        //checks to see if the file size equal to or greater than mSize
        if(file_stat.st_mode >= mSize)
        {
	  //print off the directory name, the regular file name, and the size of the regular file
	  printf("\n./%s/%s %d\n", strdup(argv[1]),  dentry->d_name,  file_stat.st_mode);

	  ++number_of_files_in_dir;//increment number of regualr files
        }
      }
    }

    //get the "next" entry
    dentry = readdir(searchD);
  }

  //return the number of regular files
  return number_of_files_in_dir;
}
