#include <bits/stdc++.h> 
using namespace std; 

int nearestSmallerEqFib(int n) 
{  
	if (n == 0 || n == 1) 
		return n; 

	int f1 = 0, f2 = 1, f3 = 1; 
	while (f3 <= n) { 
		f1 = f2; 
		f2 = f3; 
		f3 = f1 + f2; 
	} 
	return f2; 
} 

void printFibRepresntation(int n) 
{ 
	while (n > 0) { 
		int f = nearestSmallerEqFib(n); 
		cout << f << " "; 
		n = n - f; 
	} 
} 

int main() 
{ 
	int n = 30; 
	cout << "Non-neighbouring Fibonacci Representation of "
		<< n << " is \n"; 
	printFibRepresntation(n); 
	return 0; 
} 
