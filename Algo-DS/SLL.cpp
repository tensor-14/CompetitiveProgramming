#include <bits/stdc++.h>
using namespace std;

void insert(int x, int pos);
void print(struct node *temp);

struct node {
    int data;
    struct node *next;
} *head = NULL;

int main() {
    int i;
    int n; // Number of element you want to insert in the linked list
        
    cin >> n;
    int num;
    for (i = 1; i <= n; i++) {
        cin >> num;
        insert(num, i);
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
        head = nnode; // here head is assigned to first node as of now which
        // will help us to iterate through list
    } else {
        int i = 1;
        while (i != pos - 1) {
            i++;
            temp = temp->next;
        }
        if (temp->next == NULL) {
            nnode->next = NULL;
            temp->next = nnode;
        } else {
            nnode->next = (temp->next)->next;
            temp->next = nnode;
        }
    }
}

void print(struct node *temp) {
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}