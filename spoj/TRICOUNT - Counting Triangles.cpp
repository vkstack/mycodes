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
  ll t,n;
  cin>>t;
  while(t--){
    cin>>n;
    cout<<(n*(n+2)*(2*n+1))/8<<"\n";
  }
  return 0;
}
