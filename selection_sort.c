#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int n;
    struct Node* next;
}Node;

void selectionsort (Node* head)
{
    Node * cur =  head;
    while(cur != NULL)
    {
        Node* min = cur;
        Node* tmp = cur->next;

        while(tmp != NULL)
        {
            if(tmp->n < min->n)
            {
                min = tmp;
            }
            tmp = tmp->next;
        }

        if(min != cur)
        {
            int tmp = cur->n;
            cur->n = min->n;
            min->n = tmp;
        }

        cur = cur->next;
    }


}

void printlist(Node * source)
{
    while(source)
    {
        printf("%d ", source->n);
        source = source->next;
    }
    printf("\n");
}

int main()
{
    Node a, b, c, d;

    a.n = 1;
    b.n = 4;
    c.n = 8;
    d.n = 2;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    selectionsort(&a);
    printlist(&a);

    return 0;
}
