#include<iostream>
using namespace std;

#define ll long long

ll gcd(ll a,ll b){
    if( b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ll t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        ll g=gcd(a,b);
        a/=g;
        b/=g;
        a^=b;
        b^=a;
        a^=b;
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}
