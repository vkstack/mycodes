#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define ll long
int minn(int x, int y, int z)
{
    return min(min(x, y), z);
}
ll dp[2002][2002];
int main(){
    int t;
    cin>>t;
    while(t--){
        char x[2002],y[2002];
        cin>>x>>y;
        int i=0,j=0,xl=strlen(x),yl=strlen(y);
        for(i=0;i<=xl;i++)
            for(j=0;j<=yl;j++){
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(x[i-1]==y[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+minn(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        cout<<dp[i-1][j-1]<<"\n";
    }
    return 0;
}
