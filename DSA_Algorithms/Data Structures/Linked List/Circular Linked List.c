// Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *tail = NULL;  // tail points to the last node in circular linked list

void beginInsert()  // Insert at Beginning
{
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("Enter Value: ");
    scanf("%d", &newNode->data);

    if (tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    printf("\nNode Inserted at Beginning\n");
}

void endInsert()  // Insert at End
{
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("Enter Value: ");
    scanf("%d", &newNode->data);

    if (tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("\nNode Inserted at End\n");
}

int countNodes()
{
    if (tail == NULL)
        return 0;

    int count = 0;
    struct Node *ptr = tail->next; // start from head (tail->next)

    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != tail->next);

    printf("Total Nodes: %d\n", count);
    return count;
}

void insertAtIndex()  // Insert at Specific Position (1-based)
{
    int pos;
    printf("Enter Position: ");
    scanf("%d", &pos);

    int size = countNodes();

    if (pos < 1 || pos > size + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    printf("Enter Value: ");
    scanf("%d", &newNode->data);

    if (tail == NULL)  // Empty list, only pos=1 is valid
    {
        newNode->next = newNode;
        tail = newNode;
        printf("Node Inserted\n");
        return;
    }

    if (pos == 1)  // Insert at beginning
    {
        newNode->next = tail->next;
        tail->next = newNode;
        printf("Node Inserted at Beginning\n");
        return;
    }

    struct Node *ptr = tail->next; // head
    for (int i = 1; i < pos - 1; i++)
        ptr = ptr->next;

    newNode->next = ptr->next;
    ptr->next = newNode;

    if (ptr == tail)
        tail = newNode;

    printf("Node Inserted at Position %d\n", pos);
}

void beginDelete()  // Delete from Beginning
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *head = tail->next;
    if (head == tail)  // Only one node
    {
        free(head);
        tail = NULL;
    }
    else
    {
        tail->next = head->next;
        free(head);
    }
    printf("Deleted from Beginning\n");
}

void endDelete()  // Delete from End
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *ptr = tail->next;  // head
    if (ptr == tail)  // Only one node
    {
        free(ptr);
        tail = NULL;
        printf("Deleted from End\n");
        return;
    }

    while (ptr->next != tail)
        ptr = ptr->next;

    ptr->next = tail->next;
    free(tail);
    tail = ptr;

    printf("Deleted from End\n");
}

void deleteFromPosition()  // Delete from Specific Position
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    int pos;
    printf("Enter Position to Delete: ");
    scanf("%d", &pos);

    int size = countNodes();
    if (pos < 1 || pos > size)
    {
        printf("Invalid Position\n");
        return;
    }

    struct Node *head = tail->next;

    if (pos == 1)  // Delete head
    {
        beginDelete();
        return;
    }

    struct Node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
        ptr = ptr->next;

    struct Node *delNode = ptr->next;
    ptr->next = delNode->next;

    if (delNode == tail)
        tail = ptr;

    free(delNode);

    printf("Deleted Node at Position %d\n", pos);
}

void searchByValue()
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    int value;
    printf("Enter Value to Search: ");
    scanf("%d", &value);

    struct Node *ptr = tail->next;
    int pos = 1;
    do
    {
        if (ptr->data == value)
        {
            printf("Value %d Found at Position %d\n", value, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    } while (ptr != tail->next);

    printf("Value Not Found\n");
}

void searchByPosition()
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    int pos;
    printf("Enter Position: ");
    scanf("%d", &pos);

    int size = countNodes();
    if (pos < 1 || pos > size)
    {
        printf("Invalid Position\n");
        return;
    }

    struct Node *ptr = tail->next;
    for (int i = 1; i < pos; i++)
        ptr = ptr->next;

    printf("Value at Position %d is %d\n", pos, ptr->data);
}

void display()
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *ptr = tail->next;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("(back to head)\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n- Circular Singly Linked List Operations -\n\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Index\n");
        printf("4. Count Nodes\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Search by Value\n");
        printf("9. Search by Position\n");
        printf("10. Display\n");
        printf("11. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: beginInsert(); break;
            case 2: endInsert(); break;
            case 3: insertAtIndex(); break;
            case 4: countNodes(); break;
            case 5: beginDelete(); break;
            case 6: endDelete(); break;
            case 7: deleteFromPosition(); break;
            case 8: searchByValue(); break;
            case 9: searchByPosition(); break;
            case 10: display(); break;
            case 11: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
