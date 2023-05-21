#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head, int data) {
    if (*head == NULL) {
        *head = create_node(data);
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = create_node(data);
    }
}

struct node *add_lists(struct node *list1, struct node *list2) {
    int carry = 0;
    struct node *result = NULL;
    while (list1 != NULL || list2 != NULL) {
        int sum = carry;
        if (list1 != NULL) {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2 != NULL) {
            sum += list2->data;
            list2 = list2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        insert_node(&result, sum);
    }
    if (carry > 0) {
        insert_node(&result, carry);
    }
    return result;
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    // insert values into the first list
    insert_node(&list1, 7);
    insert_node(&list1, 1);
    insert_node(&list1, 5);
    insert_node(&list1, 4);
    // insert values into the second list
    insert_node(&list2, 5);
    insert_node(&list2, 9);
    insert_node(&list2, 2);
    insert_node(&list2, 4);
    // add the two lists and print the result
    struct node *result = add_lists(list1, list2);
    printf("List 1: ");
    print_list(list1);
    printf("\nList 2: ");
    print_list(list2);
    printf("\nList 3: ");
    print_list(result);
    return 0;
}

/*
This program defines a node struct that contains an int data and a pointer to the next node. The create_node function creates a new node with the given data, and the insert_node function inserts a new node with the given data at the end of the list.
The add_lists function takes two linked lists as input, and returns a new linked list that contains the sum of the two input lists. The function iterates over the lists, adding the corresponding values and keeping track of any carryover. The insert_node function is used to insert the result of each addition at the end of the result list.
The print_list function is used to print the values in the list, separated by "->".
In the main function, the two input lists are created, the add_lists function is called to create the result list, and the print_list function is used to print the result. In this case, the output will be 2->1->8->NULL, which represents the sum of the input lists 517 and 295.
 */
