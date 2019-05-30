#include <stdio.h>

long unsigned naive_gcd(long unsigned a, long unsigned b);
long unsigned euclid_gcd(long unsigned a, long unsigned b);

int main(void)
{

    printf("%ld\n", naive_gcd(238138548, 12345012));
    printf("%ld\n", euclid_gcd(238138548, 12345012));
    return 0;
}

long unsigned naive_gcd(long unsigned a, long unsigned b)
{
    long unsigned best = 0;
    for (long d = 1; d < a + b; d++)
        if (a % d == 0 && b % d == 0)
            best = d;

    return best;
}

long unsigned euclid_gcd(long unsigned a, long unsigned b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}