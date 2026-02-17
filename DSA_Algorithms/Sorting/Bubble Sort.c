// Bubble Sort

#include <stdio.h>

int main()
{
    int N, i, j, Temp;

    printf("Enter Number of Elements : ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter %d Elements : ", N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - i - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                Temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = Temp;
            }
        }
    }

    printf("Sorted Array : ");

    for(i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }

    return 0;
}
