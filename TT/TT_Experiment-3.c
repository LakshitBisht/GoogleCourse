#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node* next;
};

typedef struct node Node;

int is_palindrome(char* name) {
    int i, j;
    int len = strlen(name);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (name[i] != name[j]) {
            return 0;
        }
    }
    return 1;
}

void check_palindromes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (is_palindrome(current->name)) {
            printf("%s is a palindrome.\n", current->name);
        } else {
            printf("%s is not a palindrome.\n", current->name);
        }
        current = current->next;
    }
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    strcpy(head->name, "racecar");
    strcpy(second->name, "hello");
    strcpy(third->name, "madam");

    head->next = second;
    second->next = third;
    third->next = NULL;

    check_palindromes(head);

    return 0;
}



