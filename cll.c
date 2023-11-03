/*Circular linked list*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}cll;

void insert(cll **head);
void display(cll **head);

int main()
{
    cll *head = NULL;
    int choice;
    while(1)
    {
        printf("Enter the option:\n1.insert\n2.display\n3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(&head);
            break;
            case 2: display(&head);
            break;
            case 3 : exit(0);
        }
    }
    return 0;
}

void insert(cll **head)
{
    cll *newnode,*temp,*prev;
    newnode = (cll *)malloc(sizeof(cll));
    if(newnode == NULL)
    printf("Memory is not allocated\n");
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;;
        if(*head == NULL)
        {
            *head = newnode;
            newnode->next = *head;
        }
        else
        {
            temp = (*head)->next;
            prev = *head;
            while(*head != temp)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = newnode;
            newnode->next = *head;
        }
    }
}


void display(cll **head)
{
    cll *temp = (*head)->next;
    if((*head) == NULL)
    printf("List is empty");
    else
    {
        printf("List contains: ");
        printf("%d ",(*head)->data);
        while(*head != temp)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}