#include <bits/stdc++.h> 

using namespace std; 
#define NIL -1 
#define MAX 100 

int lookup[MAX]; 

void _init()        //initialising lookup array
{ 
	int i; 
	for (i = 0; i < MAX; i++) 
		lookup[i] = NIL; 
} 

int fib(int n)      //function to find and store fibonacci numbers
{ 
	if (lookup[n] == NIL) 
	{ 
		if (n <= 1) 
			lookup[n] = n;      //storing unsaved value
		else
			lookup[n] = fib(n - 1) + fib(n - 2);        //recursicve call and storing unsaved value
} 

return lookup[n]; 
} 
 
int main() 
{ 
	int n; 
	_init(); 
    cout<<"Enter n ";
    cin>>n;
	cout <<endl<< "Fibonacci number is " << fib(n)<<endl; 
	return 0; 
} 
