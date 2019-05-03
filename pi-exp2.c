#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

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

int main()
{
   double value;
   printf("pid: %d\n", getpid());
   value = compute_pi_baseline(50000000);
   printf("compute_pi_baseline: %f\n", value);
   value = compute_pi_leibniz(50000000);
   printf("compute_pi_leibniz: %f\n", value);
   value = compute_pi_euler(50000000);
   printf("compute_pi_euler: %f\n", value);
   return 0;
}

