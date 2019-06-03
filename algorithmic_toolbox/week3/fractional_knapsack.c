#include <stdio.h>

double get_optimal_value(int capacity, int weights[], int values[]);
int min(int a, int b);
int select_best(int n, int weights[], int values[]);

int main()
{
    int capacity = 50;
    int weights[3] = {20, 50, 30};
    int values[3] = {60, 100, 120};

    int capacity2 = 10;
    int weights2[1] = {30};
    int values2[1] = {500};

    printf("%.4f\n", get_optimal_value(capacity, weights, values));
    printf("%.4f\n", get_optimal_value(capacity2, weights2, values2));

    return 0;
}

int min(int a, int b)
{
    return a >= b ? b : a;
}

// Note: Sort the array to optimize the greedy algorithm.
double get_optimal_value(int capacity, int weights[], int values[])
{
    double value = 0.0;
    int n = (int)(sizeof(values) / sizeof(values[0]));

    int counter = 0;

    while (counter < n + 1)
    {
        if (capacity == 0)
            return value;

        int index = select_best(n, weights, values);
        int a = min(weights[index], capacity);
        value += (a * ((double)values[index] / (double)weights[index]));
        weights[index] -= a;
        capacity -= a;

        counter++;
    }

    return value;
}

int select_best(int n, int weights[], int values[])
{
    int index = 0;
    int value_per_weight = 0;

    for (int i = 0; i < n + 1; i++)
    {
        if (weights[i] != 0)
        {
            if (value_per_weight < values[i] / weights[i])
            {
                value_per_weight = values[i] / weights[i];
                index = i;
            }
        }
    }

    return index;
}