// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void beginInsert()                     // 1. Insertion at Beginning
{
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &newNode->data);

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("\nNode Inserted\n");
}

void endInsert()                    // 2. Insertion at End
{
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr;
}

void insertAtIndex()                    // 3. Insertion at Specific Index
{
    int Position;
    printf("Enter Position : ");
    scanf("%d", &Position);

    struct Node *newNode = malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &newNode->data);

    if (Position == 1)
    {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *ptr = head;
    for (int i = 1; i < Position - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("\nInvalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != NULL)
        ptr->next->prev = newNode;
    ptr->next = newNode;
}

int countNodes()                       // 4. Count Total Nodes
{
    int Count = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        Count++;
        ptr = ptr->next;
    }
    printf("Total Nodes : %d\n", Count);

    return Count;
}

void midInsert()                     // 5. Insert at Middle
{
    int Count = countNodes();
    int Mid = (Count / 2) + 1;

    struct Node *newNode = malloc(sizeof(struct Node));
    printf("\nEnter Value : ");
    scanf("%d", &newNode->data);

    if (Mid == 1)
    {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    struct Node *ptr = head;
    for (int i = 1; i < Mid - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next)
    {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
}

void beginDelete()                   // 6. Delete from Beginning
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("\nDeleted from Beginning\n");
}

void endDelete()                    // 7. Delete from End
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *ptr = head;
    if (ptr->next == NULL)
    {
        free(ptr);
        head = NULL;
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;
    free(ptr);
}

void deleteFromPosition()                   // 8. Delete from Specific Position
{
    int pos;
    printf("\nEnter Position to Delete: ");
    scanf("%d", &pos);

    if (head == NULL) return;

    struct Node *ptr = head;

    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(ptr);
        return;
    }

    for (int i = 1; i < pos && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr == NULL)    return;

    if (ptr->prev)
        ptr->prev->next = ptr->next;
    if (ptr->next)
        ptr->next->prev = ptr->prev;

    free(ptr);
}

void midDelete()                      // 9. Delete from Middle
{
    int Count = countNodes();
    int Mid = (Count / 2) + 1;

    deleteFromPosition(Mid);
}

void searchByValue()                     // 10. Search Node by Value
{
    int Value;
    printf("\nEnter Value to Search: ");
    scanf("%d", &Value);

    struct Node *ptr = head;
    while (ptr != NULL)
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

void searchByPosition()                       // 11. Search Node by Position
{
    int Position;
    printf("\nEnter Position : ");
    scanf("%d", &Position);

    struct Node *ptr = head;
    for (int i = 1; i < Position && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr)
        printf("\nValue at Position %d is %d\n", Position, ptr->data);
    else
        printf("\nPosition Not Found.\n");
}

void arrayConvert()                        // 12. Convert to Array
{
    int Size = countNodes();
    int Arr[Size];

    int i = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        Arr[i++] = ptr->data;
        ptr = ptr->next;
    }

    printf("Array : ");
    for (int j = 0; j < Size; j++)
    {
        printf("%d ", Arr[j]);
    }
    printf("\n");
}

void circularConvert()                     // 13. Convert to Circular Linked List and Print Once
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *ptr = head;

    printf("Circular List: ");

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    while (ptr != head);

    printf("\n");
}

void reverseTraversal()                     // 14. Reverse Traversal
{
    if (head == NULL)
        return;

    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    printf("Reverse Order : ");

    while (ptr != NULL)
    {
        printf("%d <- ", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

void swapPairwise()                     // 15. Swap Elements Pairwise
{
    struct Node *ptr = head;
    while (ptr && ptr->next)
    {
        int temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;
        ptr = ptr->next->next;
    }
}

void display()                         // Display the List
{
    struct Node *ptr = head;
    printf("Linked List: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    int Choice;

    while (1)
    {
        printf("\n- Doubly Linked List Operations -\n\n");
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
        printf("17. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &Choice);

        switch (Choice)
        {
            case 1 : beginInsert();              break;
            case 2 : endInsert();                break;
            case 3 : insertAtIndex();            break;
            case 4 : countNodes();               break;
            case 5 : midInsert();                break;
            case 6 : beginDelete();              break;
            case 7 : endDelete();                break;
            case 8 : deleteFromPosition();       break;
            case 9 : midDelete();                break;
            case 10 : searchByValue();           break;
            case 11 : searchByPosition();        break;
            case 12 : arrayConvert();            break;
            case 13 : circularConvert();         break;
            case 14 : reverseTraversal();        break;
            case 15 : swapPairwise();            break;
            case 16 : display();                 break;
            case 17 : exit(0);

            default: printf("Invalid Choice\n");
        }
    }
}
