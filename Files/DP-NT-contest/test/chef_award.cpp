#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v,a;
    int n;
    cin>>n;
    int b;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        a.push_back(b);
        v.push_back(b);
        
    }
    long int sum = 0;
    sort(v.begin(),v.end());
    vector<int> ::iterator itr;
    for(int i=0;i<a.size();i++)
    {
        itr = upper_bound(v.begin(),v.end(),a[i]);
        sum+=v.end() - itr;
        v.erase(itr - 1); 
    }
    cout<<sum<<endl;
}

