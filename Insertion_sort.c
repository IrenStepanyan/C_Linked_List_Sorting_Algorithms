#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node*next;
}Node;

Node* insertionsort(Node* sorted, Node* new_node)
{
    if(sorted == NULL || sorted->data >= new_node->data)
    {
        new_node->next = sorted;
        return new_node;
    }
    Node* cur = sorted;
    while (cur->next != NULL && cur->next->data < new_node->data)
    {
        cur = cur->next;
    }

    new_node->next = cur->next;
    cur->next = new_node;

    return sorted;

}

void Sortinsertion(Node** head)
{
    Node* sorted = NULL; 
    Node* curr = *head;

    while(curr != NULL)
    {
        Node*next = curr->next;  
        sorted = insertionsort(sorted, curr);
        curr = next; 
    }
    *head = sorted;
}

void printlist(Node* head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    Node a, b, c, d;

    a.data = 1;
    b.data = 12;
    c.data = 8;
    d.data = 5;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    Node*head = &a;

    Sortinsertion(&head);
    printlist(head);

    return 0;
}
