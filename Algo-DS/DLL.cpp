#include <bits/stdc++.h>
void insert(int x, int pos);
void print(struct node *temp);
using namespace std;

struct node {
    int data;
    struct node *next; // pointer to point the address of next node
    struct node *prev; // pointer to point the address of previous node
} *head = NULL;        // to point to the first node of 
        // linked list

int main() {
    int i;
    int n;
    cin >> n; // Number of nodes
    int num, p;
    cout << "Enter the value and position " << endl;
    for (i = 1; i <= n; i++) {
        cin >> num >> p;
        insert(num, p);
    }
    print(head);
    return 0;
}

void insert(int x, int pos) {
    struct node *nnode;
    nnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    nnode->data = x;
    if (head == NULL) {
        temp = nnode;
        nnode->next = NULL; // this is last node so its next->NULL
        nnode->prev = NULL; // previous pointer of first node assigned as  NULL
        head = nnode; // here head is assigned to first node as of now which will help us to iterate through list
    } else if (pos == 1) {
        head = nnode;
        nnode->next = temp;
        temp->prev = nnode;
        nnode->prev = NULL;
    } else {
        int i = 1;
        while (i != pos - 1) {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL) {
            nnode->prev = temp;
            nnode->next = NULL;
            (temp->next) = nnode;
        } else {
            nnode->next = (temp->next);
            nnode->prev = temp;
            (temp->next)->prev = nnode;
            temp->next = nnode;
        }
    }
}

void print(struct node *temp) {
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}