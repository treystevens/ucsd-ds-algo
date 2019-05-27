#include <stdio.h>

long fibonnaci(int n);
long fibonnaci_arr(int n);
long fibo_recursive(int n);

int main(void)
{
    printf("%ld\n", fibonnaci(10));
    printf("%ld\n", fibonnaci_arr(10));
    printf("%ld\n", fibo_recursive(10));

    return 0;
}

// Enter nth position of fibonnaci and returns its value
long fibonnaci(int n)
{

    int firstNum = 0;
    int secondNum = 1;
    int temp = secondNum;

    if (n <= 1)
        return n;

    for (int i = 1; i < n; i++)
    {
        secondNum += firstNum;
        firstNum = temp;
        temp = secondNum;
    }

    return secondNum;
}

long fibonnaci_arr(int n)
{
    long nums[100] = {};
    nums[0] = 0;
    nums[1] = 1;

    for (int i = 2; i <= n; i++)
        nums[i] = nums[i - 1] + nums[i - 2];

    return nums[n];
}

/**
 * 
 * 
 * T(n) = Executed lines of code.
 * 
 * if n <= 1 ------ T(n) = 2.
 * if n >= 2 ------ T(n) = 3 + T(n - 1) + T(n - 2)
 * 3 because we check the if condition, else condition and return statement.
 * T(n - [num]) is for recursively computing the fibonacci number - we need to add the amount of lines these recursive calls take.
 * 
 */

long fibo_recursive(int n)
{
    if (n <= 1)
        return n;
    else
        return fibo_recursive(n - 2) + fibo_recursive(n - 1);
}
