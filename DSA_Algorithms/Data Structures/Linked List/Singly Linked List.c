// Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void beginInsert()                  // 1. Insertion at Beginning
{
    struct Node *newNode = malloc(sizeof(struct Node));;
    int Item;

    printf("\nEnter Value : ");
    scanf("%d",&Item);

    newNode->data = Item;
    newNode->next = head;
    head = newNode;
    printf("\nNode Inserted");
}

void endInsert()                   // 2. Insertion at End
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;

    int Item;

    printf("\nEnter the Value : ");
    scanf("%d", &Item);

    newNode->data = Item;
    newNode->next = NULL;

}

void insertAtIndex()             // 3. Insertion at Specific Index
{
    int Position;
    printf("\nEnter Position : ");
    scanf("%d", &Position);

    struct Node *ptr = head, *newNode = malloc(sizeof(struct Node));
    printf("\nEnter Value : ");
    scanf("%d", &newNode->data);

    if (Position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for(int i = 1; i < Position - 1 && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void countNodes()             // 4. Count Total Nodes
{
    struct Node *ptr = head;
    int Count = 0;

    while(ptr)
    {
        Count++;
        ptr = ptr->next;
    }
    printf("Total Nodes: %d\n", Count);
}

void midInsert()            // 5. Insert at Middle
{
    struct Node *ptr = head;
    int Count = 0, Position, Item;
    while(ptr != NULL)
    {
        Count++;
        ptr = ptr->next;
    }
    Position = (Count / 2) + 1;
    ptr = head;
    printf("\nEnter Value : ");
    scanf("%d", &Item);

    for(int i = 1; i < Position-1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = Item;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void begDelete()           // 6. Delete from Beginning
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
}

void endDelete()                 // 7. Delete from End
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    free(ptr->next);
    ptr->next = NULL;
}

void deleteFromPosition()                  // 8. Delete from Specific Position
{
    int Position;
    printf("\nEnter Position to Delete : ");
    scanf("%d", &Position);

    struct Node *ptr = head, *temp;

    if (Position == 1)
    {
        head = head->next;
        free(ptr);
    }
    else
    {
        for (int i = 1; i < Position - 1 && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }
        if (ptr && ptr->next)
        {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }
}

void midDelete()                // 9. Delete from Middle
{
    struct Node *ptr = head;
    int Count = 0;

    while (ptr != NULL)
    {
        Count++;
        ptr = ptr->next;
    }

    int Middle = Count / 2 + 1;

    ptr = head;

    if (Middle == 1)
    {
        head = head->next;
        free(ptr);
    }
    else
    {
        for (int i = 1; i < Middle - 1 && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL && ptr->next != NULL)
        {
            struct Node *temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
    }
}

void searchByValue()          // 10. Search Node by value
{
    int Value;
    printf("\nEnter Value to Search : ");
    scanf("%d", &Value);

    struct Node *ptr = head;

    while(ptr != NULL)
    {
        if (ptr->data == Value)
        {
            printf("\nValue %d Found.\n", Value);
            return;
        }
        ptr = ptr->next;
    }
    printf("\nValue Not Found.\n");
}

void searchByPosition()              // 11. Search Node by Position
{
    int Position;
    printf("\nEnter Position to Search : ");
    scanf("%d", &Position);

    struct Node *ptr = head;
    for (int i = 1; i < Position && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("\nValue at Position %d : %d\n", Position, ptr->data);
    }
    else
    {
        printf("\nPosition Not Found.\n");
    }
}

void arrayConvert()           // 12. Convert to Array
{
    int Arr[100];
    int i = 0;
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        Arr[i++] = ptr->data;
        ptr = ptr->next;
    }

    printf("Array : ");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", Arr[j]);
    }
    printf("\n");
}

void circularConvert()               // 13. Convert to Circular Linked List and Print Once
{
    if (head == NULL)
    {
        return;
    }
    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
}

void reverseTraversal()              // 14. Reverse Traversal
{
    struct Node *ptr = head;
    int Arr[1000],  i = 0;

    while(ptr != NULL)
    {
        Arr[i++] = ptr->data;
        ptr = ptr->next;
    }
    printf("\nReverse Order : ");

    for (int j = i-1; j >= 0; j--)
    {
        printf("%d -> ", Arr[j]);
    }
    printf("NULL\n");
}


void swapPairwise()                // 15. Swap Elements Pairwise
{
    struct Node *ptr = head;

    while(ptr && ptr->next)
    {
        int temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;
        ptr = ptr->next->next;
    }
}

void display()              // Display the List
{
    struct Node *ptr = head;

    printf("Linked list : ");

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


void main()
{
    int Choice;

    while (1)
    {
        printf("\n- Singly Linked List Operations -\n\nChoose One Option from the Following List\n\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Index\n");
        printf("4. Count Nodes\n");
        printf("5. Insert at Middle\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Delete Middle\n");
        printf("10. Search by Value\n");
        printf("11. Search by Position\n");
        printf("12. Convert to Array\n");
        printf("13. Convert to Circular\n");
        printf("14. Reverse Traversal\n");
        printf("15. Swap Pairwise\n");
        printf("16. Show\n");
        printf("17. Exit\n\n");

        printf("Enter Your Choice : ");
        scanf("%d", &Choice);

        switch (Choice)
        {
            case 1: beginInsert();               break;
            case 2: endInsert();                 break;
            case 3: insertAtIndex();             break;
            case 4: countNodes();                break;
            case 5: midInsert();                 break;
            case 6: begDelete();                 break;
            case 7: endDelete();                 break;
            case 8: deleteFromPosition();        break;
            case 9: midDelete();                 break;
            case 10: searchByValue();            break;
            case 11: searchByPosition();         break;
            case 12: arrayConvert();             break;
            case 13: circularConvert();          break;
            case 14: reverseTraversal();         break;
            case 15: swapPairwise();             break;
            case 16: display();                  break;
            case 17: exit(0);
            default: printf("Please Enter Valid Choice\n");
        }
    }
}

