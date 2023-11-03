/*Single linked list*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}sll;

void insert_at_last(sll **head);
void insert_at_first(sll **head);
void delete_at_last(sll **head);
void delete_at_first(sll **head);
void insert_at_position(sll **head);
void display(sll **head);

int main()
{
    sll *head = NULL;
    int choice;
    while(1)
    {
        printf("Enter the option:\n1.insert_at_last\n2.insert_at_first\n3.delete_at_last\n4.delete_at_first\n5.insert_at_position\n6.display\n7.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_at_last(&head);
            break;
            case 2: insert_at_first(&head);
            break;
            case 3: delete_at_last(&head);
            break;
            case 4: delete_at_first(&head);
            break;
            case 5: insert_at_position(&head);
            break;
            case 6: display(&head);
            break;
            case 7 : exit(0);
        }
    }
    return 0;
}

void insert_at_last(sll **head)
{
    sll *newnode,*temp;
    newnode = (sll *)malloc(sizeof(sll));
    if(newnode == NULL)
    printf("Memory is not allocated\n");
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(*head == NULL)
        *head = newnode;
        else
        {
            temp = *head;
            while(temp->next != NULL)
            temp = temp->next;
            temp->next = newnode;
        }
    }
}

void insert_at_first(sll **head)
{
    sll *newnode,*temp;
    newnode = (sll *)malloc(sizeof(sll));
    if(newnode == NULL)
    printf("Memory is not allocated\n");
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(*head == NULL)
        *head = newnode;
        else
        {
            newnode->next = *head;
            *head = newnode;
        }
    }
}

void delete_at_last(sll **head)
{
    sll *temp,*prev;
    if(*head == NULL)
    printf("List is empty\n");
    else
    {
        if((*head)->next == NULL)
        {
            temp = *head;
            *head = NULL;
            printf("Deleted : %d\n",temp->data);
            free(temp);
        }
        else
        {
            temp = *head;
            prev = *head;
            while(temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            printf("Deleted : %d\n",temp->data);
            free(temp);
        }
    }
}

void delete_at_first(sll **head)
{
    sll *temp;
    if(*head == NULL)
    printf("List is empty\n");
    else
    {
        temp = *head;
        *head = temp->next;
        printf("Deleted: %d\n",temp->data);
        free(temp);
    }
}

void insert_at_position(sll **head)
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    sll *newnode,*temp = *head, *prev;
    newnode = (sll *)malloc(sizeof(sll));
    if(newnode == NULL)
    printf("Memory is not allocated\n");
    else
    {
        int data,count=1;
        printf("Enter data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(pos > 1)
        {
            while(count < pos)
            {
                prev = temp;
                temp = temp->next;
                count++;
            }
            prev->next = newnode;
            newnode->next = temp;
        }
        else
        {
            newnode->next = *head;
            *head = newnode;
        }
    }
}

void display(sll **head)
{
    sll *temp = *head;
    if(*head == NULL)
    printf("List is empty");
    else
    {
        printf("List contains: ");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}