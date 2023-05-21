#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

typedef struct node Node;

int contains_char(Node *head, char c) {
    Node *list = head;
    while (list != NULL) {
        if (list->data == c) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}

int main() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = (Node *) malloc(sizeof(Node));
    second = (Node *) malloc(sizeof(Node));
    third = (Node *) malloc(sizeof(Node));

    head->data = 'a';
    second->data = 'b';
    third->data = 'c';

    head->next = second;
    second->next = third;
    third->next = NULL;

    char chr = 'c';
    if (contains_char(head, chr)) {
        printf("The list contains %c.\n", chr);
    } else {
        printf("The list does not contain %c.\n", chr);
    }

    return 0;
}