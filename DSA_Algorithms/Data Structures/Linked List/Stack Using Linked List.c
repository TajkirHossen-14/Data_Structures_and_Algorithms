// Stack Using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node                 // Ekta Node structure banano hoyeche
{
    int data;
    struct Node *next;      // next pointer zeta porer node ke point korbe
};

struct Node *top = NULL;      // top pointer ekta node ke point korbe and shururte node ta empty

void push()     // Push funtion - Notun element stack e push korar jonno
{
    int data;       // Input er jonno data naamer ekta variable newa hoyeche

    printf("Enter Value to Push : ");
    scanf("%d", &data);         // User theke value input nibe

    struct Node *newNode = malloc(sizeof(struct Node));     // Notun ekta node create kora holo

    newNode->data = data;       // Notun node e data set kora hoyeche
    newNode->next = top;        // Notun node er next hobe ager top
    top = newNode;           // top update kore notun node ke point kora hocche
}

void pop()        // Pop function - Top theke element delete korar jonno
{
    if (top == NULL)      // Zodi stack er top empty hoy
    {
        printf("Stack is Empty\n");
        return;
    }
    struct Node *temp = top;       // temp pointer e top assign kora hoyeche

    printf("Popped : %d\n", temp->data);    // Za data pop hobe ta print korbe

    top = top->next;         // top ke update kore next node e nibe
    free(temp);       // Ager top node er memory free kore dibe
}

void showStack()        // showStack Function - Stack er shob element show korar jonno
{
    if (top == NULL)         // Stack zodi empty hoy
    {
        printf("Stack is Empty\n");   // 'Stack is Empty' print korbe
        return;                       // Function theke ber hoye zabe
    }
    struct Node *current = top;      // current pointer stack er top e set kora holo
    printf("Stack : ");

    while (current != NULL)       // Zotokkhon porzonto current NULL na hoy
    {
        printf("%d ", current->data);    // current node er data print korbe
        current = current->next;         // next node e nibe
    }
    printf("\n");         // New line print korbe
}

int main()             // Main function
{
    int Choice;        // User input er jonno Choice naamer ekta variable newa hoyeche

    while(1)       // Ekta infinity loop zeta exit kora na porzonto cholbe
    {
        printf("\n --- Stack Menu ---\n");      //Menu
        printf("\n");
        printf(" 1. Push\n");
        printf(" 2. Pop\n");
        printf(" 3. Display\n");
        printf(" 4. Exit\n");

        printf("\n Enter Your Choice : ");
        scanf("%d", &Choice);

        switch (Choice)
        {
            case 1 : push();          break;        // 1 hole push function ke call korbe
            case 2 : pop();           break;        // 2 hole pop function ke call korbe
            case 3 : showStack();     break;        // 3 hole showStack function ke call korbe
            case 4 : exit(0);

            default : printf("Invalid Choice\n");    // Onno kichu dile invalid dekhabe
        }
    }

    return 0;      // Program successful vabe shesh hoyeche
}
