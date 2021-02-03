#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C){
    if(n==1){
        cout<<"Move 1 from "<<A<<" to "<<C<<"\n";
        return;
    }
    towerOfHanoi(n-1, A, C, B);
    cout<<"Move "<<n<<" from "<<A<<" to "<<C<<"\n";
    towerOfHanoi(n-1, B, A, C);
}

int main(){

    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
