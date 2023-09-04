#include <stdio.h>
#include <omp.h>

static long int num_steps = 10000000;
double step;

#define NUM_THREADS 100

int main(){
    double start = omp_get_wtime();
    double pi, sum = 0.0;

    step = 1.0/(double) num_steps;

    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        int num_threads = omp_get_num_threads();
        int id = omp_get_thread_num();

        double x, partial_sum = 0.0;

        for(int j = id; j < num_steps; j+=num_threads){
            x = (j + 0.5)*step;
            partial_sum += 4.0/(1.0+x*x);
        }

        #pragma omp atomic
            sum+=partial_sum;

    }
    pi = sum*step;
    
    double end = omp_get_wtime();

    printf("Pi is: %f\t Wtime is: %f\n", pi, end-start);
}