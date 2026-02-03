// Circular Queue

#include <stdio.h>

int main ()
{
    int N, i;

    scanf("%d", &N);

    int Rear = -1, Front = -1;

    int Circular_Queue[N];

    while(1)
    {
        int Option;

        printf("\n\nType...\n1 to Enqueue\n2 to Dequeue\n");

        scanf("%d", &Option);

        if(Option == 1)                            // Enqueue
        {
            if((Front == 0 && Rear == N - 1) || (Rear + 1 == Front))
            {
                printf("Overflow\n");
            }

            else
            {
                int Item;

                scanf("%d", &Item);

                if(Front == -1 && Rear == -1)
                {
                    Front = Rear = 0;
                }
                else if(Rear == N - 1 && Front != 0)
                {
                    Rear = 0;
                }
                else
                {
                     Rear++;
                }


                Circular_Queue[Rear] = Item;
            }

            for(i = Front; i <= Rear; i++)
            {
                printf("%d ", Circular_Queue[i]);
            }

        }
        else if(Option == 2)                        // Dequeue
        {
            if(Rear == Front - 1)
            {
                printf("Underflow\n");
            }
            else
            {
                if(Front == Rear)
                {
                    Front = Rear = -1;
                }
                else if(Front == N - 1)
                {
                    Front = 0;
                }
                else
                {
                    Front++;
                }

            for(i = Front; i <= Rear; i++)
            {
                printf("%d ", Circular_Queue[i]);
            }

        }
    }

    return 0;
    }

}
