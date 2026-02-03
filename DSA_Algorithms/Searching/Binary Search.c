// Binary Search

#include <stdio.h>

int BinarySearch(int Arr[], int N, int Target)
{
    int Low = 0, High = N - 1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (Arr[Mid] == Target)
        {
            return Mid;
        }
        else if (Arr[Mid] < Target)
        {
            Low = Mid + 1;
        }
        else
        {
            High = Mid - 1;
        }
    }

    return -1;
}

int main()
{
    int N, Target;

    printf("Enter Number of Elements : ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter %d Elements in Sorted Order : ", N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("Enter the Element to Search : ");
    scanf("%d", &Target);

    int Result = BinarySearch(Arr, N, Target);

    if (Result != -1)
    {
        printf("Element Found at Index %d.\n", Result);
    }
    else
    {
        printf("Element Not Found!\n");
    }

    return 0;
}
