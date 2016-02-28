#include<iostream>
using namespace std;

#define ll long long
ll minPrimeDivisor[1000009];
ll prime[1000006];

ll pow(ll base,ll exp){
    ll res=1;
    while(exp>0) {
        if(exp&1)
            res=res*base;
        base*=base;
        exp>>=1;
    }
    return res;
}
void primegen(){
    for(ll i=2;i<1000006;i++)prime[i]=1;
        prime[0]=prime[1]=0;
    for(ll i=2;i<1000006;i++){
        if(prime[i])
            for(ll j=i;j<1000006;j+=i)
                if(prime[j]==1)
                    prime[j]=i;
    }
}

int main(){
    primegen();
    ll t;
    prime[0]=prime[1]=1;
    cin>>t;
    while(t--){
        ll n,ans=1;
        cin>>n;
        ll cur=prime[n],curpow=0;
        if(n==1)
            cout<<1<<"\n";
        else{
            while(n){
                if(cur==prime[n]){
                    curpow++;
                    n/=cur;
                }
                else{
                    ans*=(pow(cur,curpow-1)*(cur-1));
                    curpow=0;
                    cur=prime[n];
                    if(n==1)break;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
