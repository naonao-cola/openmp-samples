/**
 * @author RookieHPC
 * @brief Original source code at https://rookiehpc.org/openmp/docs/firstprivate/index.html
 **/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
 * @brief Illustrates the OpenMP firstprivate policy.
 * @details This example shows that when a firstprivate variable is passed to a
 * parallel region, threads work on initialised copies but that whatever
 * modification is made to their copies is not reflected onto the original
 * variable. 
 **/
int main(int argc, char* argv[])
{
	// Use 4 OpenMP threads
	omp_set_num_threads(4);

	// Variable that will be firstprivate
	int val = 123456789;

	printf("Value of \"val\" before the OpenMP parallel region: %d.\n", val);

	#pragma omp parallel firstprivate(val)
	{
		printf("Thread %d sees \"val\" = %d, and updates it to be %d.\n", omp_get_thread_num(), val, omp_get_thread_num());
		val = omp_get_thread_num();
	}

	// Value after the parallel region; unchanged.
	printf("Value of \"val\" after the OpenMP parallel region: %d.\n", val);

	return EXIT_SUCCESS;
}
