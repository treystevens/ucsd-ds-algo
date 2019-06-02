#include <stdio.h>

int get_change(int m)
{

    int n = m / 10;
    m %= 10;
    n += (m / 5);
    m %= 5;
    n += m;

    return n;
}

int main()
{
    int m;

    printf("Enter a number: ");
    scanf("%d", &m);

    printf("Output: %d\n", get_change(m));

    return 0;
}
