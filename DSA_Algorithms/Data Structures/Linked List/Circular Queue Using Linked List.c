// Circular Queue Using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node                // Ekta Node structure banano hoyeche
{
    int data;              // node e data rakhar jonno variable
    struct Node *next;     // next node er pointer
};

struct Node *front = NULL;    // Queue er shurur dike point kora hoyeche zeta shurute NULL
struct Node *rear = NULL;     // Queue er shesher dike point kora hoyeche zeta shurute NULL

void CQ_Enqueue()          // Enqueue function - Queue te notun element add korar jonno
{
    int Value;             // input er jonno variable

    printf(" Enter Value to Enqueue : ");    // User theke input chacche
    scanf("%d", &Value);                     // User theke input nibe

    struct Node *newNode = malloc(sizeof(struct Node));       // Notun ekta node create kora holo

    newNode->data = Value;            // Notun node e value assign kora hoyeche
    newNode->next = NULL;             // Notun node er next ke initially NULL kora hoyeche

    if (rear == NULL)                 // Zodi queue empty hoy
    {
        front = rear = newNode;       // front ar rear hocche first node
        rear->next = front;           // front hobe rear er next
    }
    else
    {
        rear->next = newNode;         // Ager rear er next e new node
        rear = newNode;               // Rear update kore new node e ana hoyeche
        rear->next = front;
    }
}

void CQ_Dequeue()                  // Enqueue function - Queue te notun element add korar jonno
{
    if(front == NULL)              // Zodi queue empty hoy
    {
        printf(" Queue is Empty\n");          // Empty message print korbe
        return;                               // Function theke ber hoye zabe
    }
    if (front == rear)
    {
        printf(" Dequeued : %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct Node *temp = front;                   // Front nod eke temp pointer e rakha hoyeche
        printf(" Dequeued : %d\n", temp->data);      // Data print korbe

        front = front->next;                // Front er current value update kore front ke porer node e nibe
        rear->next = front;
        free(temp);
    }
}

void ShowCircularQueue()          // Queue display korar function
{
    if (front == NULL)            // Queue zodi empty hoy
    {
        printf(" Queue is Empty\n");      // Empty queue message dibe
        return;                           // Function theke ber hoye zabe
    }

    struct Node *current = front;        // Traversal er jonno current pointer front e point kora hoyeche

    do
    {
        printf(" %d ", current->data);        // Data print korbe
        current = current->next;              // Porer node e nibe
    }
    while (current != front);           // Front na asha pozonto cholbe

    printf("\n");                       // New line print
}

int main()           // Main function
{
    int Choice;      // User input er jonno Choice naamer ekta variable newa hoyeche

    while(1)       // Ekta infinity loop zeta exit kora na porzonto cholbe
    {
        printf("\n --- Queue Menu ---\n");      //Menu
        printf("\n");
        printf(" 1. Enqueue\n");
        printf(" 2. Dequeue\n");
        printf(" 3. Display\n");
        printf(" 4. Exit\n");

        printf("\n Enter Your Choice : ");
        scanf("%d", &Choice);                // User theke input nibe

        switch(Choice)                       // Switch case check
        {
            case 1 : CQ_Enqueue();            break;        // 1 hole enqueue function ke call korbe
            case 2 : CQ_Dequeue();            break;        // 2 hole dequeue function ke call korbe
            case 3 : ShowCircularQueue();     break;        // 3 hole showQueue function ke call korbe
            case 4 : exit(0);

            default : printf(" Invalid Choice\n");    // Onno kichu dile invalid dekhabe
        }
    }

    return 0;
}
