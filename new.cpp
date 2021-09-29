#include<bits/stdc++.h>

using namespace std;

int main(){
    char str1[] = "Imnop", str2[] = "zdfgty", str3[] = "defg", str4[20];

    //cout<<strcpy(str1, str2)<<endl<<strcat(str2, str2)<<endl;
    cout<<strcat(str2, strcat(str2, strcpy(str1, str2)));

    return 0;
}