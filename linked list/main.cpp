#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL"<<endl;
}
int LengthLL(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}

void insertAtFront(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *n = new node(d);
        head = tail = n;
    }
    else
    {
        node *n = new node(d);
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
insertAtMiddle(int pos, int d, node *&head, node *&tail)
{
    node *temp = head;
    for (int i{}; i < pos - 1; ++i)
    {
        temp = temp->next;
    }

    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
}

void deletAtFront(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}
void deleteAtLast(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail; 
        temp->next = NULL;
        tail = temp;
    }
}
void reverseLL(node* &head, node* &tail)
{
    node* c= head;
    node* p= NULL;

    while(c != NULL)
    {
        node* n =c->next;
        c->next = p;
        p =c;
        c = n;
    }
    swap(head, tail);
}

void reverseLLRecursionHelper(node* c, node* p)
{
    if(c==NULL)
    {
        return;
    }
    node* n = c->next;
    c->next = p;
    reverseLLRecursionHelper(n ,c);
}
 
void reverseLLRecurion(node* &head, node* &tail)
{
    reverseLLRecursionHelper(head, NULL);
    swap(head, tail);
}

node* meregeSortedLL(node* h1, node* h2)
{
    if(h1==NULL)
    {
        return h2;
    }
    if(h2== NULL)
    {
        return h1;
    }

    node* nH = NULL;
    if(h1->data > h2->data)
    {
        nH = h2;
        nH->next = meregeSortedLL(h1, h2->next);
    }
    else{
        nH =h1;
        nH->next = meregeSortedLL(h1->next, h2);
    }
    return nH;
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
    insertAtMiddle(3, 0, head, tail);
    insertAtMiddle(5, 0, head, tail);
    printLL(head);
    cout << "\nLength: " << LengthLL(head) << endl;
    while (head != NULL)
    {
        deletAtFront(head, tail);
        printLL(head);
        cout << endl;
    }
    insertAtFront(head, tail, 1);
    insertAtFront(head, tail, 2);
    insertAtFront(head, tail, 3);
    insertAtFront(head, tail, 4);
    printLL(head);
    cout<<endl;
    // while (head != NULL)
    // {
    //     deleteAtLast(head, tail);
    //     printLL(head);
    //     cout << endl;
    // }
    // return 0;
    reverseLL(head, tail);
    printLL(head);
    cout<<endl;
    reverseLLRecurion(head, tail);
    printLL(head);
    cout<<endl;
    cout<<endl;
    node* h1 =NULL, *t1 =NULL;
    node* h2 =NULL, *t2 =NULL;
    node* nH =NULL, *nT = NULL;
    insertAtlast(h1, t1, 1);
    insertAtlast(h1, t1, 3);
    insertAtlast(h1, t1, 5);
    insertAtlast(h1, t1, 7);
    insertAtlast(h1, t1, 9);
    insertAtlast(h2, t2, 2);
    insertAtlast(h2, t2, 4);
    insertAtlast(h2, t2, 6);
    insertAtlast(h2, t2, 8);
    insertAtlast(h2, t2, 10);

    printLL(h1);
    printLL(h2);

    nH =meregeSortedLL(h1 ,h2);
    printLL(nH);

}
