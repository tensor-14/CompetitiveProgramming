#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define PI 3.1415926535897932384626
#define ll long long int
#define endl "\n"

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

ll mpow(ll base, ll exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, d, m, z=-1, leftX=(-1LL)*1e18, rightX=1e18, leftY=leftX, rightY=rightX, currPos=1;;
    leftX--;
    rightX++;
    leftY--;
    rightY++;
    string inpStr;
    while(true){
        if(currPos==1){
            if(rightX>=(leftX+2) && rightY>=(leftY+2)){
                ll midx=(rightX+leftX)/2;
                ll midy=(rightY+leftY)/2;
                cout<<currPos<<" "<<midx<<" "<<midy<<endl;
                cin>>inpStr;
                if(inpStr.compare("O")==0 || inpStr.compare("FAILED")==0){
                    break;
                }
                if(inpStr[0]=='X'){
                    leftX=midx-1;
                    rightX=midx+1;
                }
                else if(inpStr[0]=='P'){
                    if(d==0){
                        rightX=midx-1;
                    }
                    else{
                        rightX=midx;
                        leftX--;
                    }
                }
                else{
                    if(d==0){
                        leftX=midx+1;
                    }
                    else{
                    leftX=midx;
                    rightX++;
                    }
                }
                if(inpStr[1]=='Y'){
                    leftY=midy-1;
                    rightY=midy+1;
                }
                else if(inpStr[1]=='P'){
                    if(d==0){
                        rightY=midy-1;
                    }
                    else{
                    rightY=midy;
                    leftY--;
                    }
                }
                else{
                    if(d==0){
                        leftY=midy+1;
                    }
                    else{
                        leftY=midy;
                        rightY++;
                    }
                }
                if(d==0){}
                else{
                    if(rightX<=(leftX+3) && rightY<=(leftY+3)){
                        currPos=2;
                    }
                }
            }
            else{
                currPos=2;
                cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<rightY<<endl;
                cin>>inpStr;
                break;
            }
        }
        else{
            if((rightX==(leftX+3))&&((rightY==(leftY+3)))){
                cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<leftX+2<<" "<<rightY<<endl;
                cin>>inpStr;
                if(inpStr.compare("O")==0){
                    break;
                }
                else if(inpStr.compare("IN")==0){
                    rightX=leftX+2;
                }
                else{
                    leftX=leftX+2;
                    rightX++;
                }
            }
            if((rightX==(leftX+2))&&((rightY==(leftY+3)))){                    
                cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<leftY+2<<endl;
                cin>>inpStr;
                if(inpStr.compare("O")==0){}
                else if(inpStr.compare("IN")==0){        
                    cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<leftY+2<<endl;
                    cin>>inpStr;
                }
                else{        
                    cout<<currPos<<" "<<leftX<<" "<<leftY+2<<" "<<rightX<<" "<<leftY+4<<endl;
                    cin>>inpStr;
                }
                break;
            }
            if((rightX==(leftX+3))&&((rightY==(leftY+2)))){        
                cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<leftX+2<<" "<<rightY<<endl;
                cin>>inpStr;
                if(inpStr.compare("O")==0){}
                else if(inpStr.compare("IN")==0){                        
                    cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<leftX+2<<" "<<rightY<<endl;
                    cin>>inpStr;
                }
                else{        
                    cout<<currPos<<" "<<leftX+2<<" "<<leftY<<" "<<leftX+4<<" "<<rightY<<endl;
                    cin>>inpStr;
                }
                break;
            }
            else{                    
                cout<<currPos<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<rightY<<endl;
                cin>>inpStr;
                break;
            }    
        }
        cout.flush();
    }
    cout.flush();
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	/*
	#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif 
	*/

	ll t,q,d;
    cin>>t>>q>>d;
    while (t--){
        ll i, j, n, m, leftX=(-1LL)*1e18,rightX=1e18,leftY=leftX,rightY=rightX, curr=1, z=-1;
        leftX--;
        rightX++;
        leftY--;
        rightY++;
        string inpStr;
        while(true){
            if(curr==1){
                if(rightX>=(leftX+2) && rightY>=(leftY+2)){
                    ll midx=(rightX+leftX)/2;
                    ll midy=(rightY+leftY)/2;
                    cout<<curr<<" "<<midx<<" "<<midy<<endl;
                    cin>>inpStr;
                    if(inpStr.compare("O")==0 || inpStr.compare("FAILED")==0){
                        break;
                    }
                    if(inpStr[0]=='X'){
                        leftX=midx-1;
                        rightX=midx+1;
                    }
                    else if(inpStr[0]=='P'){
                        if(d==0){
                            rightX=midx-1;
                        }
                        else{
                            rightX=midx;
                            leftX--;
                        }
                    }
                    else{
                        if(d==0){
                            leftX=midx+1;
                        }
                        else{
                            leftX=midx;
                            rightX++;
                        }
                    }
                    if(inpStr[1]=='Y'){
                        leftY=midy-1;
                        rightY=midy+1;
                    }
                    else if(inpStr[1]=='P'){
                        if(d==0){
                            rightY=midy-1;
                        }
                        else{
                            rightY=midy;
                            leftY--;
                        }
                    }
                    else{
                        if(d==0){
                            leftY=midy+1;
                        }
                        else{
                            leftY=midy;
                            rightY++;
                        }
                    }
                    if(d==0){
                        
                    }
                    else{
                        if(rightX<=(leftX+3) && rightY<=(leftY+3)){
                            curr=2;
                        }
                    }
                }
                else{
                    curr=2;
                    cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<rightY<<endl;
                    cin>>inpStr;
                    break;
                }
            }
            else{
                if((rightX==(leftX+3))&&((rightY==(leftY+3)))){
                    cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<leftX+2<<" "<<rightY<<endl;
                    cin>>inpStr;
                    if(inpStr.compare("O")==0){
                        break;
                    }
                    else if(inpStr.compare("IN")==0){
                        rightX=leftX+2;
                    }
                    else{
                        leftX=leftX+2;
                        rightX++;
                    }
                }
                if((rightX==(leftX+2))&&((rightY==(leftY+3)))){               
                    cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<leftY+2<<endl;
                    cin>>inpStr;
                    if(inpStr.compare("O")==0){}
                    else if(inpStr.compare("IN")==0){
                        cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<leftY+2<<endl;
                        cin>>inpStr;
                    }
                    else{
                        cout<<curr<<" "<<leftX<<" "<<leftY+2<<" "<<rightX<<" "<<leftY+4<<endl;
                        cin>>inpStr;
                    }
                    break;
                }
                if((rightX==(leftX+3))&&((rightY==(leftY+2)))){
                    cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<leftX+2<<" "<<rightY<<endl;
                    cin>>inpStr;
                    if(inpStr.compare("O")==0){}
                    else if(inpStr.compare("IN")==0){
                        cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<leftX+2<<" "<<rightY<<endl;
                        cin>>inpStr;
                    }
                    else{
                        cout<<curr<<" "<<leftX+2<<" "<<leftY<<" "<<leftX+4<<" "<<rightY<<endl;
                        cin>>inpStr;
                    }
                    break;
                }
                else{
                    cout<<curr<<" "<<leftX<<" "<<leftY<<" "<<rightX<<" "<<rightY<<endl;
                    cin>>inpStr;
                    break;
                }
            }
            cout.flush();
        }
        cout.flush();
    }
	return 0;
}

ll mpow(ll base, ll exp) {
	base %= mod;
	ll result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((ll)result * base) % mod;
		base = ((ll)base * base) % mod;
		exp >>= 1;
	}
	return result;
}