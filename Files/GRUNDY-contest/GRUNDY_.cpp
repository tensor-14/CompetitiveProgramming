#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

#define PLAYER1 1
#define PLAYER2 2

/*----Returns the Mex----*/
ll MEX(unordered_set<ll> Set){
  ll Mex = 0;
  while (Set.find(Mex) != Set.end())
    Mex++;
  return (Mex);
} 

/*----Returns the Grundy Number----*/
ll GRUNDY(ll n, ll Grundy[]){                                                                                      
	Grundy[0] = 0;                                                                                                               
	Grundy[1] = 1;                                                                                                               
	Grundy[2] = 2;                                                                                                               
	Grundy[3] = 3;                                                                                                               
	if (Grundy[n] != -1)                                                                                                         
		return (Grundy[n]);

  unordered_set<ll> Set;                                                                                                      
	for (ll i=1; i<=3; i++)                                                                                                     
		Set.insert (GRUNDY (n-i, Grundy));                                                                                
  Grundy[n] = MEX (Set);                                                                                              
                                                                                                                               
	return (Grundy[n]);
}

/*----Finds the winner----*/
void WINNER(ll turn, ll piles[], ll Grundy[], ll n){
	ll xorValue = Grundy[piles[0]];
	for (ll i=1; i<=n-1; i++)
	xorValue = xorValue ^ Grundy[piles[i]];
	
	if (xorValue != 0){
		if (turn == PLAYER1)
			printf("THOR\n");
		else
			printf("STARK\n");
	}
	else{
		if (turn == PLAYER1)
			printf("STARK\n");
		else
			printf("THOR\n");
	}
	
	return;
}

void solve(){
	ll i, n, maximum;
	cin>>n;
	ll piles[n];
	
	for(i=0; i<n; i++)
		cin>>piles[i];

	maximum = *max_element(piles, piles + n);
	ll Grundy[maximum + 1];
	memset(Grundy, -1, sizeof(Grundy));

	for(i=0; i<=n-1; i++)
	GRUNDY(piles[i], Grundy);
	WINNER(PLAYER1, piles, Grundy, n);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	ll t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
