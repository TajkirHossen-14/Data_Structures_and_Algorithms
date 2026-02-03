// LCS Using Memoization

#include <stdio.h>
#include <string.h>

#define MAX 100

int Max(int A, int B)
{
    return (A > B) ? A : B;
}

int LCS(char *X, char *Y, int i, int j, int DP[MAX][MAX])
{
    if (X[i] == 0 || Y[j] == 0)
    {
        return 0;
    }
    else if (DP[i][j] != -1)      // Already Computed
    {
        return DP[i][j];
    }
    else if (X[i] == Y[j])
    {
        DP[i][j] = 1 + LCS(X, Y, i + 1, j + 1, DP);
    }
    else
    {
        DP[i][j] = Max(LCS(X, Y, i + 1, j, DP), LCS(X, Y, i, j + 1, DP));
    }

    return DP[i][j];
}

int main()
{
    char X[] = "KAZI";
    char Y[] = "TAJKIR";

    int M = strlen(X);
    int N = strlen(Y);

    int DP[MAX][MAX];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            DP[i][j] = -1;
        }
    }

    int i = 0, j = 0;

    int Result = LCS(X, Y, i, j, DP);

    printf("X = %s\n", X);
    printf("Y = %s\n", Y);

    printf("\n");

    printf("Length of LCS = %d\n", Result);

    return 0;
}
