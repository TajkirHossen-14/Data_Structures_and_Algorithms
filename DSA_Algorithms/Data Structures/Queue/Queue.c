// Queue
#include <stdio.h>


int main ()
{
    int Size, i;

    scanf("%d", &Size);

    int Rear = -1, Front = -1;

    int Queue[Size];

    while(1)
    {
        int Option;

        printf("\n\nType..\n1 to Enqueue\n2 to Dequeue\n3 to Check If the Queue is Empty\n4 to Check If the Queue is Full\n0 to Exit\n");

        scanf("%d", &Option);

        if(Option == 1)                            // Enqueue
        {
            if(Rear == Size - 1)
            {
                printf("Overflow\n");
            }
            else
            {
                int Item;

                Rear++;
                scanf("%d", &Item);

                Queue[Rear] = Item;
            }

            for(i = 0; i <= Rear; i++)
            {
                printf("%d ", Queue[i]);
            }

        }
        else if(Option == 2)                        // Dequeue
        {
            if(Front == Rear)
            {
                printf("Underflow\n");
            }
            else
            {
                Front++;
            }

            for(i = Front + 1; i <= Rear ; i++)
            {
                printf("%d ", Queue[i]);
            }

        }
        else if(Option == 3)
        {
            if(Front == Rear)
            {
                printf("\nQueue is Empty");
            }
            else
            {
                 printf("\nQueue is not Empty");
            }
        }
        else if(Option == 4)
        {
            if(Rear == Size - 1)
            {
                printf("\nQueue is Full");
            }
            else
            {
                printf("\nQueue is not Full");
            }
        }
        else if(Option == 0)
        {
            return ;
        }

        else printf("Invalid Input.\n");
    }

    return 0;
}

