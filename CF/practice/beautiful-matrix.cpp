#include<iostream>
using namespace std;

int main(){
    int mat[5][5], count=0, r, c;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++){
            cin>>mat[i][j];
            if(mat[i][j]==1){
                r=i;
                c=j;
            }
        }    
    if(r>2)
        count+=r-2;
    else
        count+=2-r;
    if (c>2)
        count+=c-2;
    else
        count+=2-c;
    
    cout<<count<<endl;
}