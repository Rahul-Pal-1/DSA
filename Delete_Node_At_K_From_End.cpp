#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(ListNode*  head){
    ListNode* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp;

    ListNode *first = head;
    ListNode *second = head;
    for (int i = 0; i < n; i++)
    {
        if (second->next == NULL)
        {
            if (i == n - 1)
            {
                temp = head;
                head = head->next;
                delete (temp);
            }
            return head;
        }
        second = second->next;
    }

    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    temp = first->next;
    first->next = first->next->next;
    delete temp;
    return head;
}

int main()
{
    ListNode *head = NULL;
    insertAtTail(head,22);
    insertAtTail(head,21);
    insertAtTail(head,42);
    insertAtTail(head,52);
    insertAtTail(head,12);
    display(head);
    ListNode* new_head = removeNthFromEnd(head, 3);
    display(new_head);
    return 0;
}
