#include <stdio.h>
#include <stdlib.h>

//merge sort in linked list

typedef struct
{
    int n;
    struct Node *next;
}Node;

void split( Node * source, Node** front, Node** back)
{
    if( !source || !source -> next) 
    {
        *front = source;
        *back = NULL;
        return;
    }

    int len = 0;
    Node* tmp = source;
    while(tmp)
    {
        len++;
        tmp = tmp->next;
    }

    int mid = len/2;
    Node* cur = source;
    for(int i =1; i< mid; i++)
    {
        cur = cur->next; 
    }

    *front = source;
    *back = cur->next;
    cur->next = NULL; 
}

Node * merge(Node* front, Node* back)
{
    if(!back) 
        return front;
    if(!front) 
        return back;

    Node * result =NULL;
    if(front->n <= back->n)
    {
        result = front;
        result->next = merge(front->next, back);
    }else
    {
        result = back;
        result->next = merge(front, back->next);
    }
    return result;
}

void mergesort(Node** source)
{
    Node* head = *source;
    if(!head || !head->next)
        return; 

    Node* front;
    Node* back;

    split(head, &front, &back);

    mergesort(&front); 
    mergesort(&back); 

    *source = merge(front, back);
}

void printlist(Node *head)
{
    while(head)
    {
        printf("%d ", head->n);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node a, b, c, d;

    a.n = 5;
    b.n = 3;
    c.n = 8;
    d.n = 1;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    Node* head = &a; 

    mergesort(&head);

    printlist(head);

    return 0;
}
