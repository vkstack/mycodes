#include<iostream>
using namespace std;
int main(){
    long n,i,ans=0;
    cin>>n;
    for(i=1;i*i<=n;i++)ans+=(n/i-i+1);
    cout<<ans<<"\n";
    return 0;
}
