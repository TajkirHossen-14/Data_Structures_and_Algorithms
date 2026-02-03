// 0/1 Knapsack

#include <stdio.h>

int Max(int A, int B)
{
    return (A > B) ? A : B;
}

int Knapsack(int C, int N, int Weight[], int Value[])
{

    int i, k;
    int DP[N + 1][C + 1];

    for (i = 0; i <= N; i++)
    {
        for (k = 0; k <= C; k++)
        {
            if (i == 0 || k == 0)
            {
                DP[i][k] = 0;
            }
            else if (Weight[i-1] <= k)
            {
                DP[i][k] = Max(Value[i-1] + DP[i - 1][k - Weight[i-1]], DP[i - 1][k]);
            }
            else
            {
                DP[i][k] = DP[i - 1][k];
            }

        }
    }

    return DP[N][C];
}

int main()
{
    int Value[] = {15, 10, 9, 5};
    int Weight[] = {1, 5, 3, 4};
    int C = 8;
    int N = sizeof(Value) / sizeof(Value[0]);

    printf("Maximum Value in 0/1 Knapsack : %d\n", Knapsack(C, N, Weight, Value));

    return 0;
}
