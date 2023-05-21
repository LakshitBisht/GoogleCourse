#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        this->val = INT_MIN;
        this->next = NULL;
    }
    Node(int x)
    {
        val = x;
        this->next = NULL;
    }
};

class LL
{
    Node *head;

public:
    LL()
    {
        this->head = NULL;
    }
    void insertAtBegin(int x)
    {
        Node *n1 = new Node(x);
        n1->next = head;
        head = n1;
    }
    void insertAtEnd(int x)
    {
        Node *n1 = new Node(x);
        if (head == NULL)
        {
            head = n1;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = n1;
    }
    void sorting()
    {
        Node *temp1 = head, *temp2 = head;
        while (temp1->next)
        {
            temp2 = temp1->next;
            while (temp2)
            {
                if (temp2->val < temp1->val)
                {
                    int temp = temp2->val;
                    temp2->val = temp1->val;
                    temp1->val = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
    void printList()
    {
        if (!head)
        {
            cout << "Underflow: No data to print.";
            return;
        }
        Node *temp = head;

        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
    }
};

int main()
{
    LL l1;
    l1.insertAtEnd(11);   // 11
    l1.insertAtEnd(12);   // 11 12
    l1.insertAtEnd(13);   // 11 12 13
    l1.insertAtEnd(14);   // 11 12 13 14
    l1.insertAtBegin(90); // 90 11 12 13 14 15
    l1.insertAtBegin(80); // 80 90 11 12 13 14 15
    l1.sorting();
    l1.printList();
    cout << "\n"; // 11->13->14
    return 0;
}
