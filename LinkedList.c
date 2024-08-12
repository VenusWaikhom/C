#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void InsertB(struct node **head, int no) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = no;
    new_node->next = *head;
    *head = new_node;
    printf("Successfully Added\n");
    return;
}

void InsertE(struct node **head, int no) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = no;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Successfully Added\n");
    return;
}

void insertP(struct node **head, int pos, int no) {
    int i;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = no;
    struct node *temp = *head;

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        printf("Successfully Added\n");
    } else {
        for (i = 1; i < pos - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                break;
            } else {
                temp = temp->next;
            }
        }
        if (temp == NULL || temp->next == NULL && i != pos - 1) { 
            printf("Index out of Range\n");
            free(new_node);
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
            printf("Successfully Added\n");
        }
    }
    return;
}


void Search(struct node *head, int no) {
    int pos = 0, flag = 0;
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == no) {
            printf("The number is found at %d position\n", pos + 1);
            flag = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (flag == 0) {
        printf("Given number is not found\n");
    }
    return;
}

void deleteNode(struct node **head, int no) {
    int pos = 0, flag = 0;
    struct node *temp = *head;
    struct node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == no) {
            if (pos == 0) {
                *head = temp->next;
                free(temp);
                printf("The number is found at %d position and deleted\n", pos + 1);
                flag = 1;
                return;
            } else {
                prev->next = temp->next;
                free(temp);
                printf("The number is found at %d position and deleted\n", pos + 1);
                flag = 1;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }

    if (flag == 0) {
        printf("Number not found\n");
    }
}

void display(struct node *head) {
    struct node *temp = head;
    printf("The Linked List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int i = 1, no, pos, ch;

    while (i) {
        printf("/*MENU*/\n");
        printf("1. Insert in beginning\n2. Insert at end\n3. Insert at specific position\n4. Delete\n5. Search\n6. Display Linked List\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number to be added: ");
                scanf("%d", &no);
                InsertB(&head, no);
                break;
            case 2:
                printf("Enter the number to be added: ");
                scanf("%d", &no);
                InsertE(&head, no);
                break;
            case 3:
                printf("Enter the number to be added: ");
                scanf("%d", &no);
                printf("Enter the position of the Number to be added: ");
                scanf("%d", &pos);
                insertP(&head, pos, no);
                break;
            case 4:
                printf("Enter the number to be deleted: ");
                scanf("%d", &no);
                deleteNode(&head, no);
                break;
            case 5:
                printf("Enter the number to be searched: ");
                scanf("%d", &no);
                Search(head, no);
                break;
            case 6:
                display(head);
                break;
            case 7:
                i = 0;
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
