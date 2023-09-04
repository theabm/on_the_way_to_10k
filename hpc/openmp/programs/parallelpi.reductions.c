#include <stdio.h>
#include <omp.h>

static long int num_steps = 100000000;

double step;
#define NUM_THREADS 100

int main(){
    double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;
    double start = omp_get_wtime();

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for reduction (+:sum, x)
    for (int i=0; i<num_steps; i++){
        x = (i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }
    pi = step*sum;
    double end = omp_get_wtime();

    printf("Pi is: %f\t Wtime is: %f\n", pi, end-start);
}