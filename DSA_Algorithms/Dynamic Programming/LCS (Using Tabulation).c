// LCS Using Tabulation

#include <stdio.h>
#include <string.h>

int Max(int A, int B)
{
    return (A > B) ? A : B;
}

int LCS(char *X, char *Y, int m, int n)
{
    int DP[m + 1][n + 1];   // DP Table

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                DP[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = Max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    return DP[m][n];
}

int main()
{
    char X[] = "TRAIN";
    char Y[] = "RAIN";

    int M = strlen(X);
    int N = strlen(Y);

    int Result = LCS(X, Y, M, N);

    printf("X = %s\n", X);
    printf("Y = %s\n", Y);

    printf("\n");

    printf("Length of LCS = %d\n", Result);

    return 0;
}
