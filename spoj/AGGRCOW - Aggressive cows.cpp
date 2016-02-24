#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
ll t,n,c;

int main(){
    cin>>t;
    vector<ll>v;
    while(t--){
        cin>>n>>c;
        for(long i=0,x;i<n && cin>>x;i++)
            v.push_back(x);
        sort(v.begin(),v.end());
        ll l=0,h=v[n-1],ans=-1;
        while(l<h){
            ll x=l+(h-l)/2;
            ll cows=1,startpos=v[0];
            bool fl=0;
            for(ll i=1;i<n;i++){
                if(v[i]-startpos>=x){
                    startpos=v[i];
                    cows++;
                    if(cows==c){
                        fl=1;
                        break;
                    }
                }
            }
            if(fl){
                ans=max(ans,x);
                l=x+1;
            }else
            h=x;
        }
        cout<<ans<<"\n";
        v.clear();
    }
    return 0;
}
