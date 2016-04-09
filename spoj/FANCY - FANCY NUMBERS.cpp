#include<iostream>
using namespace std;
#define ll long long

ll exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll a[30],i,j,ans=1,tmp;
    char c[31];
    for(i=0;c[i];){
      j=i+1;
      while(c[j]&&c[j]==c[i]){
        cout<<i<<" "<<j<<"\n";
        j++;
      }
      tmp=exp(2,j-i-1);
      ans*=tmp;
      // cout<<tmp<<"\n";
      i=j;
    }
  }
  return 0;
}
