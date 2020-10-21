#include <iostream>
using namespace std;
const int n = 3; // size of array for implementation 
int queuee[n];
int front = -1;
int rear = -1;
void enqueue(int x);
void dequeue();
int frontElement();
int rearElement();
bool isEmpty();
int size();

int main(){

    cout << "is queue empty? : " << isEmpty( ) << endl;
    enqueue(5);
    cout << "current size of queue : " << size( ) << endl;
    enqueue(10);
    cout << "current front element of queue : " << frontElement() << endl;
    enqueue(24);
    cout << "current size of queue : " << size( ) << endl;
    enqueue(12);
    cout << "current rear element of queue : " << rearElement() << endl;
    int s = size();
    for(int i = 0; i < s; i++){ // removing all elements
        dequeue();
    }
    dequeue();
    return 0;
}

void enqueue(int x){

    if(rear == n-1)
        cout << "Overflow condition" << endl;
    else if(rear == -1){ //insertion when queue is empty
        front = front + 1;
        rear = rear + 1;
        queuee[rear] = x;
    }
    else{
        rear = rear + 1;
        queuee[rear] = x;
    }
}

bool isEmpty(){
    
    if (rear == -1) // queue is empty
        return true;
    else
        return false;
}

void dequeue(){
    
    if(rear == -1)
        cout << "Underflow condition" << endl;
    else{        
        front = front + 1;
        if ( front > rear){
            front = -1;
            rear = -1;
        }    
    }
}

int size(){

    return rear - front + 1;
}

int frontElement(){

    return queuee[front];
}

int rearElement(){

    return queuee[rear];
}