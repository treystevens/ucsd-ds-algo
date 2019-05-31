#include <stdio.h>
#include <stdlib.h>

#define MAX_CONSTRAINT 2000000000
#define STRESS_CONSTRAINT 20000

long lcm_naive(long a, long b);
long lcm_fast(long a, long b);
void stress_test();

int main(void)
{

    stress_test();
    printf("Naive: %ld\n", lcm_naive(28851538, 1183019));
    printf("Fast: %ld\n", lcm_fast(28851538, 1183019));
    return 0;
}

long lcm_fast(long a, long b)
{
    long lcm = a * b;
    int acc = 1;
    while (a * acc <= lcm)
    {
        if ((a * acc) % b == 0)
        {
            lcm = a * acc;
            return lcm;
        }
        acc++;
    }

    return lcm;
}

long lcm_naive(long a, long b)
{
    long lcm = a * b;
    for (long i = 1; i <= lcm; i++)
        if (i % a == 0 && i % b == 0)
            return i;

    return lcm;
}

void stress_test()
{
    while (1)
    {
        int a = rand() % STRESS_CONSTRAINT + 1;
        int b = rand() % STRESS_CONSTRAINT + 1;

        printf("Input: %d %d\n", a, b);

        long res1 = lcm_naive(a, b);
        long res2 = lcm_fast(a, b);

        if (res1 != res2)
        {
            printf("Wrong Answer: %ld %ld\n", res1, res2);
            break;
        }
        else
        {
            printf("Okay!\n");
        }
        printf("\n");
    }
}