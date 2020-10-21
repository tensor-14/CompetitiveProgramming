#include <bits/stdc++.h>

void insertempty(int x);
void insertend(int x);
void insertbeg(int x);
void print(struct node *temp);
void insertbetween(int x, int pos);

using namespace std;

struct node {
    int data;
    struct node *next; // pointer to point the address of next node
} *head = NULL;        // to point to the first node of linked list

int main() {
    insertempty(10);
    insertend(30);
    insertbeg(20);
    insertbetween(50, 2);
    insertbetween(22, 2);
    print(head);
    return 0;
}

void insertempty(int x) {
    struct node *nnode;
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = x;
    if (head == NULL) {
        head = nnode;
        nnode->next = nnode;
    }
}

void insertend(int x) {
    struct node *temp;
    struct node *nnode;
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = x;
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = nnode;
    nnode->next = head;
}

void insertbeg(int x) {
    struct node *temp;
    struct node *nnode;
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = x;
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = nnode;
    nnode->next = head;
    head = nnode;
}

void insertbetween(int x, int pos) {
    struct node *temp;
    struct node *nnode;
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = x;
    temp = head;
    int i = 1;
    while (i != pos - 1) {
        temp = temp->next;
        i++;
    }
    nnode->next = temp->next;
    temp->next = nnode;
}

void print(struct node *temp) {
    while (temp->next != head) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}