#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;
int main()
{
    int i;
    double x, pi, sum = 0.0;
    double t0 = omp_get_wtime();

    step = 1.0/(double)num_steps;
    for (i=0; i<num_steps;i++){
        x = (i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }
    pi = step * sum;
    double t1 = omp_get_wtime();

    printf("pi is %f\n", pi);
    printf("execution time is %f s \n", t1-t0);
}