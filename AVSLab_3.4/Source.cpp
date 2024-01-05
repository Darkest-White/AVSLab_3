#include <iostream>
#include <omp.h>
using namespace std;

#define SIZE 10

int main() 
{
    omp_set_num_threads(SIZE);

#pragma omp parallel for ordered
    for (int i = 1; i <= SIZE; i++) 
    {

#pragma omp ordered
        for (int j = 1; j <= SIZE; j++)
        {
            cout << i << " * " << j << " = " << (i * j) << std::endl;

            if (j == 10)
            {
                cout << endl;
            }
        }
    }

    return 0;
}