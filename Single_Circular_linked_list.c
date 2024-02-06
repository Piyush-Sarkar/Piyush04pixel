#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

void createList(int n) {
    struct node* newnode, * temp;
    int data, i;
    head = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data of node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;
}

void traverseList() {
    struct node* temp;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void insertatfirst(int item) {
    struct node* ptr;
    ptr = head;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    if (head == NULL) {
        printf("\nEmpty list\n");
        head = newnode;
        head->next = head;
    }
    else {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        newnode->next = head;
        head = newnode;
        ptr->next = head;
    }
}

void insertatlast(int item) {
    struct node* ptr;
    ptr = head;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = newnode;
    newnode->next = head;
}

void deletefirst() {
    struct node* ptr, * del;
    del = head;
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    head = head->next;
    ptr->next = head;
    free(del);
}

void deletelast() {
    struct node* ptr, * preptr;
    ptr = head;
    preptr = ptr;
    while (ptr->next != head) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = head;
    free(ptr);
}

int main() {
    int n, ch, item, f;
    printf("\nEnter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    do {
        printf("\n\tMENU\t\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted:\n");
                scanf("%d", &item);
                printf("\nEnter 1 to insert the item at the beginning and 2 to insert the item at the end\n");
                scanf("%d", &f);
                if (f == 1)
                    insertatfirst(item);
                else if (f == 2)
                    insertatlast(item);
                else
                    printf("\nInvalid choice\n");
                break;
            case 2:
                printf("\nEnter 1 to delete the item at the beginning and 2 to delete the item at the end\n");
                scanf("%d", &f);
                if (f == 1)
                    deletefirst();
                else if (f == 2)
                    deletelast();
                else
                    printf("\nInvalid choice\n");
                break;
            case 3:
                printf("\nThe list is as follows:\n");
                traverseList();
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (ch != 4);

    return 0;
}
