#include<iostream>
#include<cmath>
#include <sstream>
using namespace std;
#define ll long long

int main(){
  std::ios_base::sync_with_stdio (false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;
  char s[1000];
  while(t--){
    ll x=0,y=1,i;
    bool dec=0;
    cin>>s;
    for(i=0;s[i];i++){
      if(s[i]=='.')dec=1;
      else if(dec){
        x=x*10+(ll)(s[i]-'0');
        y*=10;
      };
    }
    // cout<<x<<" ";
    while(x%2==0 && y%2==0){
      x/=2;
      y/=2;
    };
    while(x%5==0 && y%5==0){
      x/=5;
      y/=5;
    }
    cout<<y<<"\n";
  }
  return 0;
}
