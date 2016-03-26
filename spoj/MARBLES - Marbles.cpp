#include<iostream>
using namespace std;

#define ll unsigned long long
int main(){
    ll t,n,k,ans;
    cin>>t;
    while(t--){
        cin>>n>>k;
        n--;
        k--;
        ans=1;
        if(k>n-k)
            k=n-k;
        for(ll i=0;i<k;i++)
            ans=ans*(n-i)/(i+1);
        cout<<ans<<"\n";
    }
    return 0;
}
