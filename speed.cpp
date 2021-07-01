#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){
    long long int x=1152921504606846976;

    auto start=high_resolution_clock::now();
    for(int i=0; i<1e6; i++, x+=2){
        if(x>2)
            x/=2;
    }
    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout<<x<<" "<<duration.count()<<endl;
    
    auto start1=high_resolution_clock::now();
    for(int i=0; i<1e6; i++, x+=2){
        if(x>2)
            x-=2;
    }
    auto stop1=high_resolution_clock::now();

    auto duration1=duration_cast<microseconds>(stop1-start1);

    cout<<x<<" "<<duration1.count()<<endl;
}