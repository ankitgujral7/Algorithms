#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
};

void push(Node *&head, int data)
{
    Node *nya = new Node();
    nya->val = data;
    nya->next = head;
    head = nya;
}

void push_after(Node *&head, int after, int data)
{
    Node *nya = new Node();
    nya->val = data;
    while (head->val != after)
    {
        head = head->next;
    }
    Node *temp = head->next;
    head->next = nya;
    nya->next = temp;
}

void push_at_end(Node *&head, int data)
{
    Node *temp = head;
    Node *nya = new Node();
    nya->val = data;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    nya->next = NULL;
    temp->next = nya;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int len(Node* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

void reverse_by_pair(Node *&head)
{
    Node* last;
    Node *prev = head;
    if(prev!=NULL)
    {
        return;
    }
    Node *nex = prev->next;
    head = nex->next;
    nex->next = prev;
    last = prev;
    reverse_by_pair(head);
    last->next = nex;
}

int main()
{
    Node *head = new Node();
    head = NULL;
    push(head, 9);
    push(head, 8);
    push(head, 7);
    push(head, 6);
    push_after(head, 6, 10);
    push_at_end(head, 11);
    push_at_end(head, 12);
    push_at_end(head, 13);
    print(head);
    reverse_by_pair(head);
    print(head);
}