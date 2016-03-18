#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long t,h,w,a[109][109],dp[109][109];
    cin>>t;
    while(t--){
        cin>>h>>w;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                cin>>a[i][j];
                dp[i][j]=0;
            }
        for(int j=0;j<w;j++)
            dp[0][j]=a[0][j];
//        for(int i=0;i<h;i++){
//            for(int j=0;j<w;j++)
//                cout<<a[i][j]<<" ";
//            cout<<"\n";
//        }
        for(int i=1;i<h;i++){
            dp[i][0]  =a[i][0]   +max(dp[i-1][0],dp[i-1][1]);
            dp[i][w-1]=a[i][w-1] +max(dp[i-1][w-2],dp[i-1][w-1]);
            for(int j=1;j<w-1;j++)
                dp[i][j]=a[i][j] +max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]);
//            cout<<"checking\n";
//            for(int j=0;j<w;j++)
//                cout<<dp[i][j]<<"\t";
//            cout<<"\n";
        }
//        for(int i=0;i<h;i++){
//            for(int j=0;j<w;j++)
//                cout<<dp[i][j]<<"\t";
//            cout<<"\n";
//        }
        long ans=0;
        for(int i=0;i<w;i++)
            ans=max(ans,dp[h-1][i]);
        cout<<ans<<"\n";
    }
    return 0;
}
