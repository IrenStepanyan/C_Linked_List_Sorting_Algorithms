#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int n;
    struct Node *next;
    struct Node *prev;
} Node;


void printNodes(Node *head) {
    Node *tmp = head; 
    while (tmp!= NULL) {
        printf("%d ", tmp->n); 
        tmp = tmp->next;     
    }
    printf("\n");
}

void printNodesRec(Node *cur)
{
    if(cur == NULL){
        printf("\n");
        return;
    }
    printf("%d ", cur->n);
    printNodesRec(cur->next);
}

void printNodesRevRec(Node *cur)
{
    if(cur == NULL){
        printf("\n");
        return;
    }
    printNodesRevRec(cur->next); 
    printf("%d ", cur->n);
}

Node * reverse(Node * head)
{
    Node* tmp = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        // changing next and prev
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;

        curr = curr->prev; 

    }
    return tmp->prev; 
}

int main() {
    Node a, b, c, d;

    a.n = 1;
    b.n = 2;
    c.n = 3;
    d.n = 4;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    a.prev = NULL;
    b.prev = &a;
    c.prev = &b;
    d.prev = &c;

    //Print the nodes starting from the head
    printNodes(&a);
    //Using recursion
    printNodesRec (&a);

    //Print the nodes starting from the tail
    printNodesRevRec(&a);
    printf("\n");

    //New reverse list (head -> tail)
    Node *new_list = reverse(&a);
    printNodes(new_list);
    return 0;
}
