// Binary Search [Using Array]

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
    int Arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int N = sizeof(Arr) / sizeof(Arr[0]);
    int Target = 8;

    int Result = BinarySearch(Arr, N, Target);


    if (Result != -1)
    {
        printf("%d Found at Index %d.\n", Target, Result);
    }
    else
    {
        printf("Element Not Found!\n");
    }

    return 0;
}
