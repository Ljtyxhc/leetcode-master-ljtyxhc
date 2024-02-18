#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define SIZE (0x10000000)

int array[SIZE];

int calc()
{
    int a = 0, b = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if(array[i] > 500)
            a++;
        else
            b++;
    }
    return a-b;
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand()%1000;
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int result = calc();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("result = %d\n", result);
    printf("cpu_time_used = %f\n", cpu_time_used);
    return 0;
}