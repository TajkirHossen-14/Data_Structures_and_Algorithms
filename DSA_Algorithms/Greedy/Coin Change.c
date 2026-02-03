// Coin Change

#include <stdio.h>

int GreedyCoinChange(int C[], int N, int i)
{
    if (N <= 0)
    {
        return 0;
    }
    else if (C[i] <= N)
    {
        printf("%d ", C[i]);

        return  1 + GreedyCoinChange(C, N - C[i], i);
    }
    else
    {
        return GreedyCoinChange(C, N, i + 1);
    }
}

int main()
{
    int C[] = {50, 25, 20, 10, 5};
    int Amount = 140;                // Amount = N

    printf("Coins Used : ");

    int Result = GreedyCoinChange(C, Amount, 0);

    printf("\nMinimum Coins Required : %d\n", Result);

    return 0;
}
