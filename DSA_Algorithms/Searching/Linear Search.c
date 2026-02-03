// Linear Search

#include <stdio.h>

int LinearSearch(int Arr[], int N, int Key)
{
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] == Key)
        {
            return i;
        }
    }
    return -1;

int main()
{
    int N, Key;

    printf("Enter number of elements in the array: ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter %d elements:\n", N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &Key);

    int Result = LinearSearch(Arr, N, Key);

    if (Result != -1)
        printf("%d is Present at Index: %d\n", Key, Result);
    else
        printf("%d is Not Present in the Array\n", Key);

    return 0;
}

