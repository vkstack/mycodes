#include<iostream>
using namespace std;
#include<algorithm>

#define ll long long
ll dp[2009][2009];
int main(){
  ll n,i,j,a[2009];
  cin>>n;
  for(i=1;i<=n;i++){
    cin>>a[i];
    dp[i][i]=n*a[i];
  }
  for(i=1;i<n;i++){
    for(j=1;j<n+1-i;j++){
      dp[j][i+j]=max((n-i)*a[j]+dp[j+1][i+j],(n-i)*a[i+j]+dp[j][i+j-1]);
    }
  }
  cout<<dp[1][n]<<"\n";
  return 0;
}
