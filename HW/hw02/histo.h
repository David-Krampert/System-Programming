#define LETTERS 26 // number of unique “letter” characters


typedef unsigned char byte; // may be useful for casting(s)


void init_histogram(int histo[]); // set all elements of the histogram to zero


void cons_histogram(const char string[], int histo[]); // construct the histogram from string


void most_frequent(const int histo[], char* ret_val); // set *ret_val to a most occurring digit character – hence returning it


void display_histogram(int* const histo); // display the histogram sparsely
