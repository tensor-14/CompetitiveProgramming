#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

#define PLAYER1 1
#define PLAYER2 2

long long int calculateMex(unordered_set<long long int> Set){
  long long int Mex = 0;
  while (Set.find(Mex) != Set.end())
    Mex++;
  return (Mex);
} 

long long int calculateGrundy(long long int n, long long int Grundy[]){                                                                                      
	Grundy[0] = 0;                                                                                                               
	Grundy[1] = 1;                                                                                                               
	Grundy[2] = 2;                                                                                                               
	Grundy[3] = 3;                                                                                                               
	if (Grundy[n] != -1)                                                                                                         
		return (Grundy[n]);

  unordered_set<long long int> Set;                                                                                                      
	for (long long int i=1; i<=3; i++)                                                                                                     
		Set.insert (calculateGrundy (n-i, Grundy));                                                                                
  Grundy[n] = calculateMex (Set);                                                                                              
                                                                                                                               
	return (Grundy[n]);
}

void declareWinner(long long int whoseTurn, long long int piles[], long long int Grundy[], long long int n){
	long long int xorValue = Grundy[piles[0]];
	for (long long int i=1; i<=n-1; i++)
	xorValue = xorValue ^ Grundy[piles[i]];
	
	if (xorValue != 0){
		if (whoseTurn == PLAYER1)
			printf("THOR\n");
		else
			printf("STARK\n");
	}
	else{
		if (whoseTurn == PLAYER1)
			printf("STARK\n");
		else
			printf("THOR\n");
	}
	
	return;
}

void solve(){
	long long int i, j, n, m;
	cin>>n;
	long long int piles[n];
	
	for(long long int i=0; i<n; i++)
		cin>>piles[i];

	long long int maximum = *max_element(piles, piles + n);
	long long int Grundy[maximum + 1];
	memset(Grundy, -1, sizeof (Grundy));

	for (long long int i=0; i<=n-1; i++)
	calculateGrundy(piles[i], Grundy);
	declareWinner(PLAYER1, piles, Grundy, n);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	//freopen("Test01.in", "r", stdin);
	//freopen("Out01.out", "w", stdout);
	long long int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
