#include<iostream>
#include<omp.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int arr[] = {1,2,3,4,5};

	int sum = 0,min_e=999,max_e=0;
	float avg = 0;

	omp_set_num_threads(4);
	
	//Sum operation
	#pragma omp parallel for reduction(+:sum)
	for(int i = 0 ; i<5; i++)
	{
		sum += arr[i];
	}
	cout<<"\t Sum : "<<sum<<endl;

	//calculating average
	sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for(int i = 0 ; i<5; i++)
	{
		sum += arr[i];
	}
	avg = sum/5;
	cout<<"\t Average : "<<avg<<endl;

	//calculating min element
	#pragma omp parallel for reduction(min:min_e)
	for(int i = 0 ; i<5 ; i++)
	{
		if (min_e > arr[i])
		{
			min_e = arr[i];
		}
	}

	cout<<"\t Min : "<<min_e<<endl;

	//calculating max element
	#pragma omp parallel for reduction(max:max_e)
	for(int i = 0 ; i<5 ; i++)
	{
		if (max_e < arr[i])
		{
			max_e = arr[i];
		}
	}

	cout<<"\t Max : "<<max_e <<endl;

	cout<<"\t Total Threads : "<<omp_get_num_threads()<<"\n\t Max Threads : "<<omp_get_max_threads()<<"\n\t Total Processors : "<<omp_get_num_procs()<<endl<<endl;

	return 0;
}