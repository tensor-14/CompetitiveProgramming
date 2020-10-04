    #include<bits/stdc++.h> 

    using namespace std;

    int fib(int n)      //function to return fibonacci number
    { 
        if (n <= 1) 
            return n; 
        return fib(n-1) + fib(n-2);         //recursive call
    } 

    int main(){ 

        int n ; 
        cout<<"Enter n ";
        cin>>n;
        cout<<endl<<"Fibonacci number is "<<fib(n)<<endl; 
        return 0; 
    }
