#include<stdio.h>

int main()
{
    int S;
    int i;
    scanf("%d", &S);

    int Stack[S];

    int Top = -1;

    while(1)
    {
        int Option;
        printf("\nType...\n1 to Push\n2 to Pop\n3 to Check if the Stack is Empty\n4 to Check the Stack is Full\n0 to Exit\n");
        scanf("%d", &Option);

        if(Option == 1)
        {
            int Push;

            if(Top == S - 1)
            {
                printf("Overflow\n");
            }
            else
            {
                Top++;
                scanf("%d", &Push);


                Stack[Top] = Push;
            }

            for(i = 0; i <= Top; i++)
            {
                printf("%d ", Stack[i]);
            }
        }

        else if(Option == 2)
        {
            if(Top == -1)
            {
                printf("Underflow");
            }
            else
            {
                Stack[Top] = '\0';
                Top--;
            }

            for(i = 0; i <= Top; i++)
            {
                printf("%d ", Stack[i]);
            }

        }

        else if(Option == 3)
        {
            if(Top == -1)
            {
                printf("Stack is Empty");
            }
            else
            {
                 printf("Stack is not Empty");
            }
        }
        else if(Option == 4 )
        {
            if(Top == S - 1)
            {
                printf("Stack is Full");
            }
            else
            {
                printf("Stack is not Full");
            }
        }
        else if(Option == 0)
        {
            return ;
        }
        else
        printf("Invalid Input.\n");
    }

    return 0;

}
