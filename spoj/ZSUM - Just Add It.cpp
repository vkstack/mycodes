#include<iostream>
using namespace std;

#define mod 10000007
#define ll long long
ll exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

int main(){
  std::ios_base::sync_with_stdio (false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,k;
  ll ans;
  while(cin>>n>>k &&n+k){
    cout<<(exp(n,k)+exp(n,n)+2*exp(n-1,k)+2*exp(n-1,n-1))%mod<<"\n";
  }
}
