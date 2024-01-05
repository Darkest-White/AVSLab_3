#include <iostream>
#include <omp.h>
using namespace std;

#define SIZE 3

int main() 
{
    int matrix[SIZE][SIZE] = { {1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9} };

    int vector[SIZE] = { 1, 2, 3 };
    int result[SIZE] = { 0 };

#pragma omp parallel for
    for (int i = 0; i < SIZE; i++) 
    {
        int thread_num = omp_get_thread_num();

        for (int j = 0; j < SIZE; j++) 
        {
            result[i] += matrix[i][j] * vector[j];
        }

        cout << "Thread: " << thread_num << ", Index: " << i << ", Value: " << result[i] << endl;
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << "Vector:" << std::endl;
    for (int i = 0; i < SIZE; i++) 
    {
        std::cout << vector[i] << std::endl;
    }

    std::cout << "Resulting Vector:" << std::endl;
    for (int i = 0; i < SIZE; i++) 
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}