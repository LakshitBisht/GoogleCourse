/*
A data structure needs to be implemented in such a way that we have the references i.e. the addresses of the values,
None of the addresses are in continuous memory block. Each time a new value needs to be stored; we need to allocate memory.
Write a program to implement the following:
1.	Addition of a new value at a given position
2.	Print all the values in the list
3.	Delete a given value from location
*/

#include <cstdio>
#include <cstdlib>

struct linkedlist {
    int data;
    struct linkedlist *next;
};

void LLtraversal(struct linkedlist *ptr) {
    while (ptr != nullptr) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct linkedlist *insertinbetween(struct linkedlist *head, int data, int index) {
    auto *ptr = (struct linkedlist *) malloc(sizeof(struct linkedlist));
    auto *p = head;
    int i = 0;
    ptr->data = data;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct linkedlist *deleteagivenvalue(struct linkedlist *head, int value) {
    struct linkedlist *ptr = head;
    struct linkedlist *newnode = head->next;
    while (newnode->data != value && newnode->next != nullptr) {
        newnode = newnode->next;
        ptr = ptr->next;
    }
    if (newnode->data == value) {
        ptr->next = newnode->next;
        free(newnode);
    }
    return head;
}

struct linkedlist *deleteatindex(struct linkedlist *head, int index) {
    struct linkedlist *ptr = head;
    struct linkedlist *newnode = head->next;
    for (int i = 0; i != index - 1; ++i) {
        ptr = ptr->next;
        newnode = newnode->next;
    }
    ptr->next = ptr->next->next;
    free(newnode);
    return head;
}

int main() {
    struct linkedlist *head;
    struct linkedlist *second;
    struct linkedlist *third;
    head = (struct linkedlist *) malloc(sizeof(struct linkedlist));
    second = (struct linkedlist *) malloc(sizeof(struct linkedlist));
    third = (struct linkedlist *) malloc(sizeof(struct linkedlist));

    head->data = 10;
    head->next = second;
    second->data = 15;
    second->next = third;
    third->data = 20;
    third->next = nullptr;
    printf("Original Linked List:\n");
    LLtraversal(head);

    head = insertinbetween(head, 27, 2);
    printf("\nInsertion in between:\n");
    LLtraversal(head);

    head = deleteagivenvalue(head, 15);
    printf("\nDeletion of a given value:\n");
    LLtraversal(head);

    head = deleteatindex(head, 1);
    printf("\nDeletion at given location:\n");
    LLtraversal(head);
    return 0;
}