#include<iostream>
using namespace std;

#define ll long long
ll minPrimeDivisor[1000009];
ll prime[1000006];

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
    for(ll i=0;i<100;i++)
//        if(prime[i])
            cout<<prime[i]<<"\n";
    ll t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        cout<<192+(k-1)*250<<"\n";
    }
}
