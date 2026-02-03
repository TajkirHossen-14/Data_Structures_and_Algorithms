// LCS Using Recursion

#include <stdio.h>

int Max(int A, int B)
{
    return (A > B) ? A : B;
}

int LCS(char *X, char *Y, int i, int j)
{
    if (X[i] == 0 || Y[j] == 0)
    {
        return 0;
    }

    if (X[i] == Y[j])
    {
        return 1 + LCS(X, Y, i + 1, j + 1);
    }
    else
    {
        return Max(LCS(X, Y, i + 1, j), LCS(X, Y, i, j + 1));
    }
}

int main()
{
    char X[] = "BANGLADESH";
    char Y[] = "JAPAN";

    int i = 0, j = 0;

    int Result = LCS(X, Y, i, j);

    printf("X = %s\n", X);
    printf("Y = %s\n", Y);

    printf("\n");

    printf("Length of LCS = %d\n", Result);

    return 0;
}
