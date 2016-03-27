#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

long C,n,fun[1000],ci[1000],dp[1000][1000],cost;
long maxFun(){
    long i,c;
    cost=0;
    for(i=0;i<=n;i++){
        for(c=0;c<=C;c++){
            if(i==0||c==0)
                dp[i][c]=0;
            else if(ci[i-1]<=c)
                dp[i][c]=max(fun[i-1]+dp[i-1][c-ci[i-1]],dp[i-1][c]);
            else
                dp[i][c]=dp[i-1][c];
        }
    }
    for(c=C;c;c--)
        if(dp[n][c]<dp[n][C])
            break;
    cost=c+1;
    return dp[n][C];
}
int main(){
    while(cin>>C>>n && C+n){
        for(long i=0;i<n;i++)
            cin>>ci[i]>>fun[i];
        long ans=maxFun();
        cout<<cost<<" "<<ans<<"\n";
    }
    return 0;
}
