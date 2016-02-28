#include<iostream>
using namespace std;

#define mod 1000000007
#define ll long long

ll f[1000009];
int main(){
    f[0]=0;
    f[1]=1;
    for(ll i=2;i<1000000;i++)
        f[i]=(f[i-1]%mod+f[i-2]%mod)%mod;
    for(i=1;i<1000000;i++)
        f[i]+=f[i-1];
    ll t,m,n;
}
