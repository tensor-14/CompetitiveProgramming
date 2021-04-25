#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int gcd(int x, int y){
    if(x == 0)
        return y;
    
    return gcd(y % x, x);
}

int nth_travel_number(int n, int a, int b){
    int lcm = a / gcd(a, b) * b;
    long int low = 0;
    long int high = (long) n * min(a,b);

    while(low < high){
        long mid = low + (high - low) / 2;
        if(mid / a + mid / b - mid / lcm < n)
            low = mid + 1;
        else
            high = mid;
    }
    return (int) (low % MOD);
}

int main(){
    int t;
    cin >> t;
    int n[t], a[t], b[t];

    for(int i = 0; i < t; ++i)
        cin >> n[i] >> a[i] >> b[i];
    
    for(int i = 0; i < t; ++i)
        cout << nth_travel_number(n[i], a[i], b[i]) << endl;
    
    return 0;
}