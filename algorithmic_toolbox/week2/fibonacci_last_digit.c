#include <stdio.h>
#include <stdlib.h>

int fibonacci_naive(unsigned long nums[], int n);
int fibonacci_fast(int nums[], int n);
void stress_test();

unsigned long fibo_slow_nums[10000000] = {};
int fibo_fast_nums[10000000] = {};

int main(void)
{
    // stress_test();
    printf("%d\n", fibonacci_fast(fibo_fast_nums, 327305));

    return 0;
}

void stress_test()
{
    while (1)
    {
        int n = rand() % 70;
        printf("Input: %d\n", n);

        int res1 = fibonacci_naive(fibo_slow_nums, n);
        int res2 = fibonacci_fast(fibo_fast_nums, n);

        if (res1 != res2)
        {
            printf("Wrong answer: %d %d\n", res1, res2);
            break;
        }
        else
        {
            printf("Okay!\n");
            printf("Answer: %d %d\n", res1, res2);
            printf("\n");
            printf("\n");
        }
    }
}

int fibonacci_fast(int nums[], int n)
{
    nums[0] = 0;
    nums[1] = 1;

    for (int i = 2; i <= n; i++)
        nums[i] = (nums[i - 1] + nums[i - 2]) % 10;

    return nums[n];
}

int fibonacci_naive(unsigned long nums[], int n)
{

    nums[0] = 0;
    nums[1] = 1;

    for (int i = 2; i <= n; i++)
        nums[i] = nums[i - 1] + nums[i - 2];

    printf("Original Fibo: %ld\n", nums[n]);
    return nums[n] % 10;
}
