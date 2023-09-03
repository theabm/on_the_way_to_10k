#include <omp.h>
#include <stdio.h>
int main()
{

    #pragma omp parallel
    {
        int my_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        printf("Hi from thread %d of %d\n", my_id, num_threads);
    }
}