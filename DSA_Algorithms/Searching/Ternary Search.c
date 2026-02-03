// Ternary Search

#include <stdio.h>

int TernarySearch(int Arr[], int Left, int Right, int Key)
{
    if (Left <= Right)
    {

        int Mid1 = Left + (Right - Left) / 3;
        int Mid2 = Right - (Right - Left) / 3;

        if (Arr[Mid1] == Key)
        {
            return Mid1;
        }
        else if (Arr[Mid2] == Key)
        {
            return Mid2;
        }
        else if (Key < Arr[Mid1])
        {
            return TernarySearch(Arr, Left, Mid1 - 1, Key);
        }
        else if (Key > Arr[Mid2])
        {
            return TernarySearch(Arr, Mid2 + 1, Right, Key);
        }
        else
        {
            return TernarySearch(Arr, Mid1 + 1, Mid2 - 1, Key);
        }
    }

    return -1;
}

int main()
{
    int N, Key;

    printf("Enter Number of Elements in the Array : ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter the Elements in Ascending Order : ");
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("Enter the Key to Search : ");
    scanf("%d", &Key);

    int Result = TernarySearch(Arr, 0, N - 1, Key);

    if (Result != -1)
        printf("%d is Present at Index  %d\n", Key, Result);
    else
        printf("%d is Not Present in the Array\n", Key);

    return 0;
}
