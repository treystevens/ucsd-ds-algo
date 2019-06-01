#include <stdio.h>
#include <stdlib.h>

#define MAX_CONSTRAINT_N 1e18
#define MAX_CONSTRAINT_M 1000
#define MIN_CONSTRAINT_N 1
#define MIN_CONSTRAINT_M 2

long get_fibonacci_huge_naive(long n, long m);
long fibonacci_huge_fast(long n, long m);
void stress_test();

int main()
{
    // stress_test();
    printf("%ld\n", fibonacci_huge_fast(239, 1000));
    printf("%ld\n", fibonacci_huge_fast(2816213588, 239));
    printf("%ld\n", fibonacci_huge_fast(MAX_CONSTRAINT_N, MAX_CONSTRAINT_M));
    printf("%ld\n", fibonacci_huge_fast(MAX_CONSTRAINT_N, MIN_CONSTRAINT_M));
    printf("%ld\n", fibonacci_huge_fast(MIN_CONSTRAINT_N, MIN_CONSTRAINT_M));

    return 0;
}

long fibonacci_huge_fast(long n, long m)
{
    if (n <= 1)
        return n;

    long nums[10000] = {};
    int period = 0;
    int len = m * m;

    nums[0] = 0;
    nums[1] = 1;

    for (int i = 2; i <= len; i++)
    {
        nums[i] = (nums[i - 1] + nums[i - 2]) % m;
        period++;

        if (nums[i] % m == 1 && nums[i - 1] % m == 0)
            break;
    }

    return nums[n % period];
}

long get_fibonacci_huge_naive(long n, long m)
{
    if (n <= 1)
        return n;

    unsigned long previous = 0;
    unsigned long current = 1;

    for (long i = 0; i < n - 1; i++)
    {
        unsigned long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// Integer overflow occurs with n > 93 on naive algorithm.
void stress_test()
{
    while (1)
    {
        int n = rand() % 93 + 1;
        int m = rand() % 1000 + 2;

        printf("Input: %d %d\n", n, m);

        long res1 = get_fibonacci_huge_naive(n, m);
        long res2 = fibonacci_huge_fast(n, m);

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
