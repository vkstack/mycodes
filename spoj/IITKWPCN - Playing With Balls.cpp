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
    ll x,y;
    cin>>x>>y;
    if(y&1)
      cout<<"1.000000\n";
    else
      cout<<"0.000000\n";
  }
  return 0;
}
