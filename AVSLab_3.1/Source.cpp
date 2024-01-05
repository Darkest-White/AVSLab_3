#include<iostream>
#include<omp.h>
using namespace std;


int main(int argc, char* argv[])
{
	srand(time(0));

	int mas1[10], mas2[10];
	int C[10];

	for (int i = 0; i < 10; i++)
	{
		mas1[i] = rand() % 101;
		mas2[i] = rand() % 101;
	}

#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < 10; i++)
		{
			C[i] = mas1[i] + mas2[i];
		}

#pragma omp for
		for (int i = 0; i < 10; i++)
		{
			cout << "Thread:" << omp_get_thread_num() << endl;
			cout << "C[" << i << "] = " << C[i] << endl;
		}
	}
	return 0;
}