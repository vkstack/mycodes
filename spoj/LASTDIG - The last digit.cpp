#include<iostream>
using namespace std;


int main(){
    long long t,a,b,ans,i;
    cin>>t;
    while(t--){
        ans=1;
        cin>>a>>b;
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
