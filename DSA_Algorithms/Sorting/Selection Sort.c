#include<stdio.h>
                                                                       //Selection
int main()
{
     int N, i, j;
     printf("Enter Array Size : ");
     scanf("%d", &N);

     int Arr[N];
     printf("Enter the Array Elements : ");
     for(i = 0; i < N; i++)
     scanf("%d", &Arr[i]);

     for(i = 0; i < N; i++)
     {
          int Min = i;
          for(j=i+1; j<N; j++)
          {
              if(Arr[j]  < Arr[Min])
              {
                  Min = j;
              }
          }

     int Temp = Arr[i];
     Arr[i] = Arr[Min];
     Arr[Min] = Temp;
     }

      for(i = 0; i < N; i++)
      {
          printf("%d ", Arr[i]);
      }

     return 0;

}
