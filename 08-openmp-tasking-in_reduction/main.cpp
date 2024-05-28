/**
 * @author RookieHPC
 * @brief Original source code at https://rookiehpc.org/openmp/docs/in_reduction/index.html
 **/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

/**
 * @brief Illustrates how to use the in_reduction clause.
 * @details This example consists in calculating the max of all elements of an
 * array.
 **/
int main(int argc, char* argv[])
{
	// Use 2 threads when creating OpenMP parallel regions
	omp_set_num_threads(2);

	int value = 0;
	const int ARRAY_SIZE = 100;
	int* myArray = (int*)malloc(sizeof(int) * ARRAY_SIZE);
	if(myArray == NULL)
	{
		printf("Cannot allocate the array \"myArray\".\n");
		return EXIT_FAILURE;
	}

	// Initialise the array
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		myArray[i] = i;
	}

	// Calculate the max of all elements

	// 1st method: a parallel loop via tasks
	#pragma omp parallel reduction(task, max: value)
	{
		#pragma omp single
		{
			for(int i = 0; i < ARRAY_SIZE; i++)
			{
				#pragma omp task in_reduction(max: value)
				{
					value = fmax(value, myArray[i]);
				}
			}
		}
	}
	printf("The max of all array elements with the 1st method is equal to %d.\n", value);

	// 2nd method: a taskgroup
	value = 0;
	#pragma omp parallel
	{
		#pragma omp single
		{
			#pragma omp taskgroup task_reduction(max: value)
			{
				for(int i = 0; i < ARRAY_SIZE; i++)
				{
					#pragma omp task in_reduction(max: value)
					value = fmax(value, myArray[i]);
				}
			}
		}
	}
	printf("The max of all array elements with the 2nd method is equal to %d.\n", value);

	free(myArray);

	return EXIT_SUCCESS;
}
