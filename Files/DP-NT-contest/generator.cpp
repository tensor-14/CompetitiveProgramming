#include<bits/stdc++.h> 
using namespace std; 

#define T 100000	//10^5
#define A 50
#define K 5

int main(){ 
	freopen ("Test01.in", "w", stdout); 

	srand(time(NULL)); 
	
//	printf("%d\n", T);
	for(int i=1; i<=T; i++){ 
		//int k = 2 + rand() % K;
		long long int a=1 + rand() % A;
		//long long int b=1 + rand() % a;
		printf("%lld", a); 
		printf("\n"); 
	} 
	printf("\n");
	fclose(stdout); 
	return(0); 
} 

