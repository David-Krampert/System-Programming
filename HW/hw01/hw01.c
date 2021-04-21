#include <stdio.h>
#include <math.h>


void factor_power(int input)
{
	int counter = 0;
	int boolean = 0;

	printf("%d = ", input);

	while(input%2 == 0)
	{
		//printf("%d^", 2);
		input = input/2;
		counter = counter + 1;
		boolean = 1;
	}

	if(boolean == 1)
	{
		printf("%d^", 2);
		printf("%d  ", counter);
	}

	for(int i = 3; i <= sqrt(input); i = i + 2)
	{
		int counter_2 = 0;
		boolean = 0;
		//boolean2 = 0;

		while(input % i == 0)
		{
			//printf("%d ", i);
			input = input / i;
			counter_2 = counter_2 + 1;
			boolean = 1;
			//boolean2 = 1;
		}
		if(boolean == 1)
		{
			//printf("* ");
			printf("%d^", i);
			printf("%d  ", counter_2);
		}
	}

//	if(boolean2 == 1)
//		printf("* ");


	if(input > 2)
		printf("%d^1 ", input);

}


int main (int argc, char** argv)
{
	printf("\n");

	int input;
	int loop = 1;
	while(loop < 2){

	  printf("Enter an integer (> 1) : ");

	  scanf("%d", &input);

	  if(input > 1){
	   break;
	  }

	  printf("\n");
	}
	printf("\n");
	factor_power(input);

	printf("\n");
	printf("\n");
	return 0;
}
