#include<bits/stdc++.h> 
using namespace std; 

#define RUN 1000
#define MAX 10000
#define MAXNUM 10 

int main(){ 
	freopen ("Test03.in", "w", stdout); 

	srand(time(NULL)); 
	
	printf("%d\n", RUN);
	for(int i=1; i<=RUN; i++){ 
		int NUM = 1 + rand() % MAXNUM; 
		printf("%d\n", NUM); 

		for (int j=1; j<=NUM; j++) 
			printf("%d ", rand() % MAX); 

		printf("\n"); 
	} 
	printf("\n");
	fclose(stdout); 
	return(0); 
} 

