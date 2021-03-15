#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int pr[n][3], flag=0, count=0;

    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin>>pr[i][j];

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            if(pr[i][j])
                flag++;
        if(flag>=2)
            count++;
        flag=0;
    }
        
    cout<<count<<endl;
    return 0;
}