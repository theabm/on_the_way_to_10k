#include <omp.h>
#include <stdio.h>
int main()
{

    printf("I am the master thread and I will print only once!\n");
    #pragma omp parallel
    {
        printf("I am a lowly thread among many, hello!\n");
    }
}