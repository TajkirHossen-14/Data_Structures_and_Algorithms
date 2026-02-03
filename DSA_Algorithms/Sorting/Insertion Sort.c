#include<stdio.h>
                                                                    //Insertion
int main()
{
     int N, i, j;
     printf("Enter Array Size : ");
     scanf("%d", &N);

     int Arr[N];
     printf("Enter the Array Elements : ");

     for(i = 0; i < N; i++)
     {
           scanf("%d", &Arr[i]);
     }

     for(i = 0; i < N; i++)
     {
           int Temp = Arr[i];
           j = i - 1;

           while(j>=0 && Arr[j] < Temp)
           {
                Arr[j + 1] = Arr[j];
                j--;
           }
           Arr[j+1] = Temp;

     }
      for(i = 0; i < N; i++)
      printf("%d ", Arr[i]);

      int Key;
      int Low = 0, High = N-1, Mid = -1;
      scanf("%d", &Key);

      while(Key = -1)
      {
           if(Low == High || Arr[Low] == Arr[High])
           {
                printf("Not Found");
           }

           Mid = Low + (High - Low) / (Arr[High] - Arr[Low] * (Key - Arr[Low]));

           if(Arr[Mid] == Key)
           {
                 printf("Found at Index %d", Mid);
                 break;
           }

           else
           {
                 if(Arr[Mid] < Key)
                 {
                     Low = Mid + 1;
                 }
                 else
                 {
                     High = Mid -1;
                 }
           }
      }


     return 0;

}
