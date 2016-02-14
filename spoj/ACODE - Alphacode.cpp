#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char ch[5002];
    int a[5002],i,dp[5002];
    long long unsigned ans,ansp,anspp;
    while(cin>>ch&&strcmp(ch, "0")){
        i=0;
        while(ch[i]){
            a[i]=ch[i]-'0';
            i++;
        }
        memset(dp,0,sizeof dp);
        dp[0]=1;
        int len=strlen(ch);
        for(i=1;i<len;i++){
            int tmp=a[i-1]*10+a[i];
            if(a[i]) dp[i]=dp[i-1];
            if(tmp<27 && tmp>9){
                if(i<2)
                    dp[i]+=dp[0];
                else
                    dp[i]+=dp[i-2];
            }
        }
        cout<<dp[len-1]<<"\n";
    }
    return 0;
}

