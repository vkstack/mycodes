#include<iostream>
using namespace std;

#define ll long long
#define mx 10000000
ll dp[mx+1];
ll maxprofit(ll n){
    if(n<4)
        return dp[n];
    ll n2=n/2,n3=n/3,n4=n/4;
    n2=n2<mx?dp[n2]:maxprofit(n2);
    n3=n3<mx?dp[n3]:maxprofit(n3);
    n4=n4<mx?dp[n4]:maxprofit(n4);
    return max(n,n2+n3+n4);
}
int main(){
    ll i;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(i=4;i<mx;i++)
        dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
    ll n;
    while(cin>>n)
        cout<<maxprofit(n)<<"\n";
    return 0;
}
