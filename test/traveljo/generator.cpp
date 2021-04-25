#include<bits/stdc++.h> 
using namespace std; 

#define T 20
#define K 400

int main(){ 
	freopen ("Test02.in", "w", stdout); 

	srand(time(NULL)); 
	
	printf("%d\n", T);
	for(int i=1; i<=T; i++){ 
		//int k = 2 + rand() % K;
		long long int a=2 + rand() % K;
		long long int b=2+rand()%K;
		long long int n=1+rand()%10000;
		//long long int b=1 + rand() % a;
		printf("%lld %lld %lld", n, a, b); 
		printf("\n"); 
	} 
	printf("\n");
	fclose(stdout); 
	return(0); 
} 

