// Factorial

#include <stdio.h>

int Fact(int N, int DP[])
{
    if (N == 0 || N == 1)
    {
        return 1;
    }
    else if (DP[N] != -1)
    {
        return DP[N];
    }
    else
    {
        return DP[N] = N * Fact(N - 1, DP);
    }
}

int main()
{
    int N;
    printf("Enter the Value of N : ");
    scanf("%d", &N);

    int DP[N + 1];
    for(int i = 0; i <= N; i++)
    {
        DP[i] = -1;
    }

    printf("Factorial(%d) = %d\n", N, Fact(N, DP));
    return 0;
}
