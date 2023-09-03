#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 20

static long num_steps = 100000000;
double step;
int main()
{
    double pi = 0.0;
    int nthreads;
    double t0 = omp_get_wtime();
    double partial_sum[NUM_THREADS];

    step = 1.0/(double)num_steps;

    // we *request* these threads, but the OS can give us less!
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        double x = 0.0;
        int i;

        // we check since it is not guaranteed that 
        // we get 10 threads
        int num_threads = omp_get_num_threads();
        // I get my id
        int my_id = omp_get_thread_num();

        // the master thread updates the shared variable 
        if(my_id==0) nthreads = num_threads;

        for (i=my_id, partial_sum[my_id] = 0.0; i<num_steps;i+=num_threads){
        x = (i+0.5)*step;
        partial_sum[my_id] += 4.0/(1.0+x*x);
        }
        }
    for(int i = 0; i<nthreads;++i){
    pi+=partial_sum[i]*step;
    }
    double t1 = omp_get_wtime();

    printf("pi is %f\n", pi);
    printf("execution time is %f s \n", t1-t0);
}