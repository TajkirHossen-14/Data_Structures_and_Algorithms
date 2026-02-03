// Fibonacci

#include <stdio.h>

int Fib(int N, int DP[])
{
    if (N == 0 || N == 1)
    {
        return N;
    }
    else if (DP[N] != -1)
    {
        return DP[N];
    }
    else
    {
        return DP[N] = Fib(N - 1, DP) + Fib(N - 2, DP);
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

    printf("Fibonacci(%d) = %d\n", N, Fib(N, DP));

    return 0;
}
