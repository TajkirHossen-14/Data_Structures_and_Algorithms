// Quick Sort

#include <stdio.h>

void QuickSort(int Arr[], int Low, int High)
{
    if (Low < High)
    {
        int pi = Partition(Arr, Low, High);

        QuickSort(Arr, Low, pi - 1);
        QuickSort(Arr, pi + 1, High);
    }
}

void Swap(int *a, int *b)
{
    int Temp = *a;
    *a = *b;
    *b = Temp;
}

int Partition(int Arr[], int Low, int High)
{
    int Pivot = Arr[Low];
    int i = Low + 1;
    int j = High;

    while (i <= j)
    {
        while (i <= High && Arr[i] < Pivot)
        {
            i++;
        }
        while (j >= Low && Arr[j] > Pivot)
        {
            j--;
        }
        if (i < j)
        {
            Swap(&Arr[i], &Arr[j]);
        }
    }

    Swap(&Arr[j], &Arr[Low]);

    return j;
}

int main()
{
    int Arr[] = {75, 15, 28, 30, 14, 90, 53};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int Low = 0, High = n - 1;

    QuickSort(Arr, Low, High);

    printf("\nSorted Array : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");

    return 0;
}

