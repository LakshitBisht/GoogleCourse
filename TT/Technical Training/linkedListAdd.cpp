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

void insertEnd(node *head, int val)
{
    node *newNode = createNode(val);
    node *tempHead = head;
    while (tempHead->next != NULL)
        tempHead = tempHead->next;
    tempHead->next = newNode;
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

node *add(node *head1, node *head2)
{
    node *head = NULL;
    int sum = 0, carry = 0;
    while (head1 != NULL || head2 != NULL)
    {
        sum = head1->digit + head2->digit + carry;
        if (sum > 9)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        else
            carry = 0;
        if (head == NULL)
            head = createNode(sum);
        else
            insertEnd(head, sum);
        head1 = head1->next;
        head2 = head2->next;
    }
    if (carry)
        insertEnd(head, carry);
    return head;
}

int main()
{
    node *head1 = createNode(9);
    insertStart(head1, 9);
    insertStart(head1, 9);
    insertStart(head1, 8);
    displayLL(head1);
    node *head2 = createNode(1);
    insertStart(head2, 4);
    insertStart(head2, 2);
    insertStart(head2, 5);
    displayLL(head2);

    node *head3 = add(head1, head2);
    displayLL(head3);
    return 0;
}