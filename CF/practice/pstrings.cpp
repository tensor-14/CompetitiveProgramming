#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1;
    cin>>str2;
    transform(str1.begin(), str1.end(), str1.begin(),::tolower);
    transform(str2.begin(), str2.end(), str2.begin(),::tolower);
    cout<<str1.compare(str2)<<endl;
}