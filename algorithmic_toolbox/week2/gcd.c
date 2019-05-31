#include <stdio.h>
#include <stdlib.h>

long naive_gcd(long a, long b);
long euclid_gcd(long a, long b);
void stress_test();

int main(void)
{

    stress_test();
    printf("%ld\n", naive_gcd(238138548, 12345012));
    printf("%ld\n", euclid_gcd(238138548, 12345012));
    return 0;
}

long euclid_gcd(long a, long b)
{
    if (b == 0)
        return a;

    return euclid_gcd(b, a % b);
}

long naive_gcd(long a, long b)
{
    long best = 0;
    for (long d = 1; d < a + b; d++)
        if (a % d == 0 && b % d == 0)
            best = d;

    return best;
}

// Contraints 1 <= n <= 2 * 10e9
// Stress testing up to 2 * 10e7
void stress_test()
{

    while (1)
    {
        int a = rand() % 20000000 + 1;
        int b = rand() % 20000000 + 1;

        int res1 = naive_gcd(a, b);
        int res2 = euclid_gcd(a, b);

        printf("Input: %d %d\n", a, b);

        if (res1 != res2)
        {
            printf("Wrong answer: %d %d\n", res1, res2);
            break;
        }
        else
        {
            printf("Okay!\n");
        }
    }
}