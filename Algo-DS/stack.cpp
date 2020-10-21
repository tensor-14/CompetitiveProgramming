#include <iostream>
using namespace std;
const int n = 3; // size of array for implementation 
int stackk[n];
int top = -1;
void push(int x);
void pop();
int topElement();
bool isEmpty();
int size();

int main(){

    cout << "is stack empty? : " << isEmpty( ) << endl;
    push(5);
    cout << "current size of stack : " << size( ) << endl;
    push(10);
    push(24);
    cout << "current size of stack : " << size( ) << endl;
    push(12);
    cout << "current top element of stack : " << topElement() << endl;
    for(int i = 0; i < size( ); i++) // removing all elements
        pop();
    pop();
    return 0;
}

void push(int x){
    
    if (top == n-1)
        cout << "Overflow condition" << endl;
    else{
        top = top + 1;
        stackk[top] = x;
    }
}

bool isEmpty(){
    
    if (top == -1) // stack is empty
        return true;
    else
        return false;
}

void pop(){
    
    if (isEmpty())
        cout << "Underflow condition" << endl;
    else
        top = top - 1;
}

int size(){
    
    return top + 1;
}

int topElement(){
    
    return stackk[top];
}