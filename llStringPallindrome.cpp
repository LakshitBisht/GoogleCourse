#include <iostream>
using namespace std;

struct node
{
    char nameChar;
    node *next;
};

node *createNode(char nameChar)
{
    node *newNode = new node;
    newNode->nameChar = nameChar;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(node *head, char val)
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
            cout << tempHead->nameChar << " ";
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
    if (head1->nameChar != head2->nameChar)
        return false;
    head2 = head2->next;
    return true;
}

int main()
{
    cout << "Enter the Name : ";
    string name;
    cin >> name;
    node *head1 = createNode(name[0]);
    for (int i = 1; i < name.length(); i++)
        insertEnd(head1, name[i]);
    displayLL(head1);
    if (checkPallindrome(head1, head1))
        cout << "Linked List is Pallindrome!\n";
    else
        cout << "Linked List is Not Pallindrome!\n";
    return 0;
}