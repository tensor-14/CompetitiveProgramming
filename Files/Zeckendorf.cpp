
	#include <bits/stdc++.h> 
	using namespace std; 

	//function to find the largest fibonacci number smaller than n
	int fib_search(int n){

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

	//function to display the found fibonacci number
	void display_fib(int n){ 

		while (n > 0) { 
			int f = fib_search(n); 
			cout << f << " "; 
			//updating n
			n = n - f;          
		} 
	} 

	int main(){ 
		
		int n; 
		cout<<"Enter the number n ";
		cin>>n;
		cout <<endl<< "Non-neighbouring Fibonacci Representation of "
			<< n << " is \n"; 
		display_fib(n); 
		return 0; 
	} 
