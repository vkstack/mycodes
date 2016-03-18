#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long long n,x,ans=0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&x);
        ans^=x;
    }
    cout<<ans;
    return 0;
}
