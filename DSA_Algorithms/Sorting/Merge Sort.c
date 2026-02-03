// Merge Sort

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int Arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(Arr, l, m);
        MergeSort(Arr, m + 1, r);
        Merge(Arr, l, m, r);
    }
}

void Merge(int Arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    int i, j;

    for (i = 0; i < n1; i++)
    {
        L[i] = Arr[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        M[j] = Arr[q + 1 + j];
    }

    i = 0, j = 0;
    int k = p;

    while(i < n1 && j < n2)
    {
        if (L[i] > M[j])
        {
            Arr[k] = M[j];
            j++;
        }
        else
        {
            Arr[k] = L[i];
            i++;
        }
        k++;
    }
    while (i < n1)
    {
        Arr[k] = L[i];
        i++, k++;
    }
    while (j < n2)
    {
        Arr[k] = M[j];
        j++, k++;
    }
}

int main()
{
    int Arr[] = {6, 3, 9, 5, 2, 8, 7, 1};

    int n = sizeof(Arr) / sizeof(Arr[0]);

    printf("Original Array : ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }

    MergeSort(Arr, 0, n - 1);

    printf("\nSorted Array :   ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }

    printf("\n");

    return 0;
}
