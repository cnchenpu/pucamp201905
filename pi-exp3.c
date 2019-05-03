#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

double compute_pi_baseline(size_t N)
{
   double pi = 0.0;
   double dt = 1.0 / N;
   for (size_t i = 0; i < N; i++)
   {
        double x = (double) i / N;
   	pi += dt / (1.0 + x * x);
   }
   return pi * 4.0;
}

double compute_pi_leibniz(size_t N)
{
   double pi = 0.0;
   for (size_t i = 0; i < N; i++) 
   {
        double tmp = (i & 1) ? (-1) : 1;
        pi += tmp / (2 * i + 1);
   }
   return pi * 4.0;
}

double compute_pi_euler(size_t N)
{
   double pi = 0.0;
   for (size_t i = 1; i < N; i++) 
   {
        pi += 1.0 / (i * i);
   }
   return sqrt(pi * 6);
}

int main(int argc, char const *argv[])
{
   struct timespec start = {0, 0};
   struct timespec end = {0, 0};

   if (argc < 2) {
	printf("Usage: %s <# of samples>\n", argv[0]);
        return -1;
   }	

   int N = atoi(argv[1]);
   int i, loop = 25;

   /*
   double value;
   printf("pid: %d\n", getpid());
   sleep(10);
   
   value = compute_pi_baseline(50000000);
   printf("compute_pi_baseline: %f\n", value);
   value = compute_pi_leibniz(50000000);
   printf("compute_pi_leibniz: %f\n", value);
   value = compute_pi_euler(50000000);
   printf("compute_pi_euler: %f\n", value);
   */

   // Baseline
   clock_gettime(CLOCK_ID, &start);
   for (i = 0; i < loop; i++) 
   {
        compute_pi_baseline(N);
   }
   clock_gettime(CLOCK_ID, &end);
   printf("%lf ", (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

   // Leibniz
   clock_gettime(CLOCK_ID, &start);
   for (i = 0; i < loop; i++)
   {
        compute_pi_leibniz(N);
   }
   clock_gettime(CLOCK_ID, &end);
   printf("%lf ", (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

   // Euler
   clock_gettime(CLOCK_ID, &start);
   for (i = 0; i < loop; i++)
   {       
         compute_pi_euler(N);
   }
   clock_gettime(CLOCK_ID, &end);
   printf("%lf ", (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

   return 0;
}

