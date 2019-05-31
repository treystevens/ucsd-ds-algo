#include <stdio.h>

#define N1 3
#define N2 10
#define N3 5

unsigned long max_pair_product(int nums[], int n);

int main()
{

    int test1[N1] = {1, 2, 3};
    int test2[N2] = {7, 5, 14, 2, 8, 8, 10, 1, 2, 3};
    int test3[N3] = {2, 9, 3, 1, 9};

    printf("%ld\n", max_pair_product(test1, N1));
    printf("%ld\n", max_pair_product(test2, N2));
    printf("%ld\n", max_pair_product(test3, N3));

    return 0;
}

// Using Pointers
// Runs O(n)
unsigned long max_pair_product(int nums[], int n)
{
    int max = nums[1];
    int second_max = nums[0];
    int *p = nums;
    for (; p < nums + n; p++)
    {
        if (max < *p)
        {
            second_max = max;
            max = *p;
        }
        else if (second_max < *p)
            second_max = *p;
    }

    return max * second_max;
}

// Using regular array indexing
/*****
unsigned long max_pair_product(int nums[], int n)
{
    int max = nums[1];
    int second_max = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (max < nums[i])
        {
            second_max = max;
            max = nums[i];
        }
        else if (second_max < nums[i])
            second_max = nums[i];
    }

    return max * second_max;
}
******/