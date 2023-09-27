#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        newNode->next = newNode;
        *head = newNode;
    } 
    else 
    {
        struct Node* current = *head;
        while (current->next != *head) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void insertBeforePosition(struct Node** head, int data, int position) 
{
    if (*head == NULL || position <= 1) 
    {
        insertAtEnd(head, data); 
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    for (int i = 1; i < position - 1; i++) 
    {
        if (current->next == *head) 
        {
            break;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirstNode(struct Node** head) 
{
    if (*head == NULL) 
    {
        return;
    }
    struct Node* current = *head;
    while (current->next != *head) 
    {
        current = current->next;
    }
    if (current == *head) 
    {
        *head = NULL;
    } 
    else 
    {
        current->next = (*head)->next;
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteAfterPosition(struct Node** head, int position) 
{
    if (*head == NULL || position <= 0) 
    {
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position; i++) 
    {
        current = current->next;
    }
    struct Node* temp = current->next;
    if (temp != *head) 
    {
        current->next = temp->next;
        free(temp);
    }
}

void display(struct Node* head) 
{
    if (head == NULL) 
    {
        return;
    }
    struct Node* current = head;
    do 
    {
        printf("%d -> ", current->data);
        current = current->next;
    } 
    while (current != head);
    printf("... (circular)\n");
}

void menu()
{
    struct Node* head = NULL;
    int choice, data, position;
    restart:
    printf("\nPress 1 to Insert at end\n");
    printf("Press 2 to Insert before specified position\n");
    printf("Press 3 to Delete first node\n");
    printf("Press 4 to Delete node after specified position\n");
    printf("Press 5 to Display circular linked list\n");
    printf("Press 6 to Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            goto restart;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertBeforePosition(&head, data, position);
            goto restart;
        case 3:
            deleteFirstNode(&head);
            goto restart;
        case 4:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAfterPosition(&head, position);
            goto restart;
        case 5:
            display(head);
            goto restart;
        case 6:
            printf("Exit.\n");
            break;
        default:
            printf("Wrong Choice.\n");
            goto restart;

    }
}
int main() 
{
    menu();
    system("PAUSE");
    return 0;
}