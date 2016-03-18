#include<iostream>
#include<string.h>
using namespace std;
int main(){
    long long t,a,b,ans,i;
    char c[1003];
    cin>>t;
    while(t--){
        ans=1;
        cin>>c>>b;
        a=c[strlen(c)-1]-'0';
        a%=10;
        if(b==0)
            cout<<1<<"\n";
        else{
            for(b%=4,i=1;i<=b+4;i++)
                ans=(ans*a)%10;
            cout<<ans<<"\n";
        }
    }
}
