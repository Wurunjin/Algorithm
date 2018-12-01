#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int t,n;cin>>t;
    while(t--){cin>>n;cout<<floor(pow(10,fmod(n*log10(n),1.0)))<<endl;}
}
