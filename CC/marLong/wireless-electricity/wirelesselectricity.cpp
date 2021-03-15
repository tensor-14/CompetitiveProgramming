#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 100000;
const int MOD = (int)1e9+7;
int factorialNumInverse[N + 1];
int naturalNumInverse[N + 1];
int fact[N + 1];
void InverseofNumber(int p) {
 naturalNumInverse[0] = naturalNumInverse[1] = 1;
 for (int i = 2; i <= N; i++)
  naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(int p) {
 factorialNumInverse[0] = factorialNumInverse[1] = 1;
 for (int i = 2; i <= N; i++)
  factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(int p) {
 fact[0] = 1;
 for (int i = 1; i <= N; i++) {
  fact[i] = (fact[i - 1] * i) % p;
 }
}
int Binomial(int N, int R, int p) {
    if(R>N) return 0;
    if(R==N) return 1;
 int ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
 return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    factorial(MOD);
    InverseofNumber(MOD);
    InverseofFactorial(MOD);
    vector<pii> cities;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        cities.push_back({x,y});
    }
    vector<pair<pii, pii>> lines;
    for(int i=0; i<m; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        lines.push_back({{x1,y1},{x2,y2}});
        if(i==0)
        {
            cout<<(-x1-1)<<" "<<(-y1)<<endl;
        } else if(i==1)
        {
            cout<<(1000001-x1)<<" "<<(1000000-y1)<<endl;
        } else
        {
            int d1 = (1000001-x1)*(1000001-x1) + (1000000-y1)*(1000000-y1);
            int d2 = (-x1-1)*(-x1-1) + (-y1)*(-y1);
            if(d1<d2)
            {
                cout<<(1000001-x1)<<" "<<(1000000-y1)<<endl;
            } else
            {
                cout<<(-x1-1)<<" "<<(-y1)<<endl;
            }
        }
    }
}
