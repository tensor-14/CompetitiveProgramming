#include<bits/stdc++.h> 
using namespace std; 

#define T 100	//10^5
#define A 1000
#define K 100

int main(){ 
	freopen ("Test02.in", "w", stdout); 

	srand(time(NULL)); 

	for(int i=1; i<=T; i++){ 
		long long int a=1 + rand() % A;
		printf("%lld", a); 
		printf("\n"); 
		for(long long int j=1; j<=a; j++)
			printf("%lld ", 1LL+rand()%K);
	} 
	printf("\n");
	fclose(stdout); 
	return(0); 
} 

