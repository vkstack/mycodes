#include<iostream>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,T,D,avail=0,x;
        cin>>n>>T>>D;
        while(n-- && cin>>x)
            avail+=((x-1)/D);
        if(avail>=T)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
