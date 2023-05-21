#include <iostream>
using namespace std;

struct node
{
    int digit;
    node *next;
};

node *createNode(int digit)
{
    node *newNode = new node;
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

void insertStart(node *&head, int val)
{
    node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}
void displayLL(node *head)
{
    if (head == NULL)
        cout << "Empty Linked List!\n";
    else
    {
        cout << "Linked List: ";
        node *tempHead = head;
        while (tempHead != NULL)
        {
            cout << tempHead->digit << " ";
            if (tempHead->next != NULL)
                cout << "-> ";
            else
                cout << endl;
            tempHead = tempHead->next;
        }
    }
}

bool checkPallindrome(node *head1, node *&head2)
{
    if (head1->next != NULL)
        if (!checkPallindrome(head1->next, head2))
            return false;
    if (head1->digit != head2->digit)
        return false;
    head2 = head2->next;
    return true;
}

int main()
{
    node *head1 = createNode(2);
    insertStart(head1, 2);
    insertStart(head1, 9);
    insertStart(head1, 9);
    insertStart(head1, 2);
    insertStart(head1, 2);
    displayLL(head1);
    if (checkPallindrome(head1, head1))
        cout << "Linked List is Pallindrome!\n";
    else
        cout << "Linked List is Not Pallindrome!\n";
    return 0;
}