#include <iostream>
#include <omp.h>
using namespace std;

#define SIZE 100

int main() 
{
    srand(time(0));

    int A[SIZE];
    int B[SIZE];
    int sum = 0;

    for (int i = 0; i < SIZE; i++) 
    {
        A[i] = rand() % 101;
        B[i] = rand() % 101;
    }

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < SIZE; i++) 
    {
        sum += A[i] * B[i];
    }

    cout << "Sum: " << sum << endl;

    return 0;
}