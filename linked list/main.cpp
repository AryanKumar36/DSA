#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printLL(node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void insertAtFront(node* &head, node* &tail, int d)
{
    if (head == NULL)
    {
        node* n = new node(d);
        head = tail = n;
    }
    else
    {
        node* n = new node(d);
        n->next = head;
        head = n;
    }
}

void insertAtlast(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *n = new node(d);
        head = tail = n;
    }
    else
    {
        node *n = new node(d);
        tail->next = n;
        n->next = NULL;
        tail = n;
    }
}

int main()
{
    node *head = NULL, *tail = NULL;
    insertAtFront(head, tail, 1);
    insertAtFront(head, tail, 2);
    insertAtFront(head, tail, 3);
    insertAtFront(head, tail, 4);
    insertAtlast(head, tail, 1);
    insertAtlast(head, tail, 2);
    insertAtlast(head, tail, 3);
    insertAtlast(head, tail, 4);
    insertAtlast(head, tail, 5);

    printLL(head);
    return 0;
}
