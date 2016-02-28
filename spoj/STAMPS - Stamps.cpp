#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
int main(){
    ll t,scn=0;
    cin>>t;
    vector<ll>v;
    while(t--){
        scn++;
        ll X,n,x,sm=0;
        cin>>X>>n;
        for(ll i=0;i<n;i++){
            cin>>x;
            sm+=x;
            v.push_back(x);
        }
        cout<<"Scenario #"<<scn<<":\n";
        if(sm<X)
            cout<<"impossible";
        else{
            sort(v.begin(),v.end());
            ll ans=0;
            sm=0;
            for(ll i=n-1;i>=0;i--){
                if(sm>=X)
                    break;
                ans++;
                sm+=v[i];
            }
            cout<<ans;
        }
        cout<<"\n";
        v.clear();
    }
    return 0;
}
