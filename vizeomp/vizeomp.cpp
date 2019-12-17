#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
const int n = 50; // 50 elemanlı dizi tutacak
float x[n];
float y[n];
double w = 0.25;
double f(double s)
{

	return (2 * s * s) + ((0.5) * s); //formül
}
//bol bol paralel döngüsü
int main()
{
#pragma omp parallel{
	int a = 6;//thread sayisi manuel olarak değişecek bu değişken üzerinden	
	omp_set_num_threads(a);
	int id = omp_get_thread_num();
	int i;
#pragma omp for
	for ( i = 0; i < a  ;i++)
	{
		id = i;
		printf("thread %d\n",id);
		

	}
#pragma omp for
	for ( i = 0; i < n; i++)
	{
		x[i] = i;
		printf("x degeri %f \n", x[i]);

	}
#pragma omp for 
	for ( i = 0; i < n; i++)
	{
#pragma omp critical
		double s = x[i] * w;
		y[i] = x[i] *w* f(s);
		printf("y degeri %f id degeri:%d :\n", y[i],id);
		omp_get_wtime();
	}
	return 0;
	}

