#include <stdio.h>
#include <stdlib.h>

int fibonacci_sum_naive(long n);
int fibonacci_sum(long n);
void stress_test();

int main(void)
{
    // stress_test();
    printf("Test: %d\n", fibonacci_sum(129382360));
    printf("Naive: %d\n", fibonacci_sum_naive(129382360));
    printf("Test: %d\n", fibonacci_sum(3));
    printf("Naive: %d\n", fibonacci_sum_naive(3));
    printf("Test: %d\n", fibonacci_sum(100));
    printf("Naive: %d\n", fibonacci_sum_naive(100));

    return 0;
}

// Same runtime as naive. Not fast enough.
int fibonacci_sum(long n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;
    int sum = 1;

    for (long i = 2; i <= n + 2; ++i)
    {
        long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    sum = current - 1;
    if (sum == -1)
        sum = 9;

    return sum;
}

int fibonacci_sum_naive(long n)
{
    if (n <= 1)
        return n;

    long previous = 0;
    long current = 1;
    long sum = 1;

    for (long i = 0; i < n - 1; ++i)
    {
        long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

void stress_test()
{
    while (1)
    {
        int n = rand() % 90 + 1;

        printf("Input: %d\n", n);

        long res1 = fibonacci_sum_naive(n);
        long res2 = fibonacci_sum(n);

        if (res1 != res2)
        {
            printf("Wrong answer: %ld %ld\n", res1, res2);
            break;
        }
        else
            printf("Okay!\n");

        printf("\n");
    }
}
