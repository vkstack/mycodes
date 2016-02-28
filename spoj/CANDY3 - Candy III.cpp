#include<iostream>
#include<cstdio>
using namespace std;

#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,ans=0;
        cin>>n;
        for(ll i=0,x;i<n;i++){
            cin>>x;
            x%=n;
            ans+=x;
            ans%=n;
        }
        if(ans%n==0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
}
