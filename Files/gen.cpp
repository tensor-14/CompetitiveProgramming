#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
typedef long long int ll;
 
#define pb push_back
 
const ll MAX = 1e5;
 
ll randomRange(ll lower, ll upper){
	ll num = (rand() % (upper - lower + 1)) + lower;
  return num;
}
 
char randchar(char lower, char upper){
  char num = (rand() % (upper - lower + 1)) + lower;
  return num;
}
 
string randomChoice(ll probability, ll n){
  string s;
  for (int i = 0; i < n; i++)
    s += randchar('0', '1');
  return s;
}
 
int main(){
    
	ofstream fout, fin;
  fin.open("input_P(3).in"); // The input filename
  fout.open("output_P(3).out"); // The output filename
 
  ll n = randomRange(1, 1e3);
  fin << n << endl;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    s[i] = randomChoice(randomRange(1, 10), randomRange(1, 1e3));
    fin << s[i];
    fin << endl;
  }
    
	for (int i = 0; i < s.size(); i++){
    if (s[i][0] == '0'){
      fout << 0 << endl;
    }
    else{
      ll ans = 0, flag0 = 0, flag1 = 0;
      for (int j = 0; j < s[i].size(); j++){
        if (s[i][j] == '1'){
          if (ans != 0)
            break;
          flag1 = 1;
        }
        else{
          flag0 = 1;
            if (flag1 and s[i][j] == '0')
              ans++;
        }
      }
      fout << ans << endl;
    }
  }
  
	fin.close();
  fout.close();
}
