#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

// Function prototypes
void createList(int n);
void traverseList();
void insertatfirst(int item);
void insertatlast(int item);
void insertbefore(int elem, int item);
void insertafter(int elem, int item);
void deletefirst();
void deletelast();
void deletebefore(int elem);
void deleteafter(int elem);

int main() {
    int n, ch, item, elem;
    printf("\nEnter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    do {
        printf("\n\tMENU\t\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Delete First\n");
        printf("6. Delete Last\n");
        printf("7. Delete Before\n");
        printf("8. Delete After\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted at first: ");
                scanf("%d", &item);
                insertatfirst(item);
                break;
            case 2:
                printf("\nEnter the element to be inserted at last: ");
                scanf("%d", &item);
                insertatlast(item);
                break;
            case 3:
                printf("\nEnter the element before which the item will be inserted: ");
                scanf("%d", &elem);
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                insertbefore(elem, item);
                break;
            case 4:
                printf("\nEnter the element after which the item will be inserted: ");
                scanf("%d", &elem);
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                insertafter(elem, item);
                break;
            case 5:
                deletefirst();
                break;
            case 6:
                deletelast();
                break;
            case 7:
                printf("\nEnter the element before which the data will be deleted: ");
                scanf("%d", &elem);
                deletebefore(elem);
                break;
            case 8:
                printf("\nEnter the element after which the data will be deleted: ");
                scanf("%d", &elem);
                deleteafter(elem);
                break;
            case 9:
                printf("\nThe list is as follows:\n");
                traverseList();
                break;
            case 10:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (ch != 10);

    return 0;
}



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
}

void traverseList() {
    struct node* temp;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatfirst(int item) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = head;
    head = newnode;
}

void insertatlast(int item) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    struct node* temp;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertbefore(int elem, int item) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    struct node* ptr, * preptr;
    if (head->data == elem)
        insertatfirst(item);
    ptr = head;
    while (ptr->data != elem) {
        preptr = ptr;
        ptr = ptr->next;
    }
    newnode->next = ptr;
    preptr->next = newnode;
}

void insertafter(int elem, int item) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    struct node* ptr;
    ptr = head;
    while (ptr->data != elem)
        ptr = ptr->next;
    newnode->next = ptr->next;
    ptr->next = newnode;
}

void deletefirst() {
    struct node* temp;
    temp = head;
    head = head->next;
    free(temp);
}

void deletelast() {
    struct node* temp;
    if (head == NULL) {
        printf("\nEmpty list\n");
        return;
    }
    if (head->next == NULL) {
        temp = head;
        printf("\nIt is a single-element list\n");
        head = NULL;
        free(temp);
        return;
    }
    temp = head;
    while ((temp->next)->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deletebefore(int elem) {
    struct node* ptr, * preptr;
    if (head->data == elem)
        deletefirst();
    ptr = head;
    while ((ptr->next)->data != elem) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}

void deleteafter(int elem) {
    struct node* ptr, * temp;
    ptr = head;
    while (ptr->data != elem)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}
