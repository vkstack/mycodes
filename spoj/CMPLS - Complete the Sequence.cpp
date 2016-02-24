#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
int main(){
    ll t,s,c,x;
    ll v[109][109];
    cin>>t;
    while(t--){
        cin>>s>>c;
        for(ll i=0;i<s&&cin>>x;i++)
            v[0][i]=x;
        ll tmp=0,ss=s;
        bool fl=1;

        for(ll i=1;i<s;i++){
            for(ll j=0;j<s-i;j++)
                v[i][j]=v[i-1][j+1]-v[i-1][j];
            ss--;
            tmp++;
//            for(ll k=0;k<=ss;k++)
//                cout<<v[i][k]<<" ";
//            cout<<"\n";

        }
        for(ll i=0;i<c;i++)
            v[tmp][ss+i]=v[tmp][0];
//        cout<<v[tmp-1][0]<<"\n";
        while(tmp--){
            for(ll i=1;i<=c;i++)
                v[tmp][ss+i]=v[tmp][ss+i-1]+v[tmp+1][ss+i-1];
            ss++;
        }
        for(ll i=s;i<s+c;i++)
            cout<<v[0][i]<<" ";
        cout<<"\n";
    }
    return 0;
}
