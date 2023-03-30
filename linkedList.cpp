#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    node *createNode(int data)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void insertStart(int val)
    {
        node *newNode = createNode(val);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int val)
    {
        node *newNode = createNode(val);
        node *tempHead = head;
        while (tempHead->next != NULL)
            tempHead = tempHead->next;
        tempHead->next = newNode;
    }

    void insertPos(int val, int pos)
    {
        node *newNode = createNode(val);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node *tempHead = head;
            int flag = 0;
            for (int i = 0; i < pos - 1; i++)
            {
                if (tempHead == NULL)
                {
                    cout << "Invalid Position!\n";
                    flag++;
                    break;
                }
                tempHead = tempHead->next;
            }
            if (flag == 0)
            {
                newNode->next = tempHead->next;
                tempHead->next = newNode;
            }
        }
    }

    void deleteValue(int val)
    {
        node *tempNode;
        int flag = 0;
        if (val == head->data)
        {
            tempNode = head;
            head = head->next;
            flag++;
        }
        else
        {
            node *tempHead = head;
            while (tempHead->next != NULL)
            {
                if (tempHead->next->data == val)
                {
                    tempNode = tempHead->next;
                    tempHead->next = tempHead->next->next;
                    flag++;
                    break;
                }
                tempHead = tempHead->next;
            }
        }
        delete tempNode;
        tempNode = NULL;
        if (flag)
            cout << "Element Deleted Successfully!" << endl;
        else
            cout << "Element Not Found!" << endl;
    }

    void displayLL()
    {
        if (head == NULL)
            cout << "Empty Linked List!\n";
        else
        {
            cout << "Linked List: ";
            node *tempHead = head;
            while (tempHead != NULL)
            {
                cout << tempHead->data << " ";
                if (tempHead->next != NULL)
                    cout << "-> ";
                else
                    cout << endl;
                tempHead = tempHead->next;
            }
        }
    }
};

int main()
{
    int ch;
    LinkedList LL;
    while (true)
    {
        cout << "\nLinked List Menu" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at a Position" << endl;
        cout << "4. Delete an Element" << endl;
        cout << "5. Display Linked List" << endl;
        cout << "6. Exit" << endl
             << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "Enter a Value: ";
            cin >> val;
            LL.insertStart(val);
            break;
        }
        case 2:
        {
            int val;
            cout << "Enter a Value: ";
            cin >> val;
            LL.insertEnd(val);
            break;
        }
        case 3:
        {
            int val, pos;
            cout << "Enter a Value and a Position: ";
            cin >> val >> pos;
            LL.insertPos(val, pos);
            break;
        }
        case 4:
        {
            int val;
            cout << "Enter the Value to be Deleted: ";
            cin >> val;
            LL.deleteValue(val);
            break;
        }
        case 5:
        {
            LL.displayLL();
            break;
        }
        case 6:
            exit(0);

        default:
            cout << "Invalid command!\n";
        }
    }

    return 0;
}