#include<bits/stdc++.h> 
using namespace std; 

#define T 1000	//10^5
#define A 10000
#define K 10000000
#define x 1000

int main(){ 
	freopen ("Test02.in", "w", stdout); 

	srand(time(NULL)); 

	for(int i=1; i<=T; i++){ 
		long long int a=1 + rand() % A;
		long long int c=1 + rand() % K;

		printf("%lld %lld", a, c); 
		printf("\n"); 
		for(long long int i=1; i<=a; i++){
			printf("%lld ", 1LL+rand()%x);
		}
		printf("\n");
	} 
	printf("\n");
	fclose(stdout); 
	return(0); 
} 

