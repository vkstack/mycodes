#include<iostream>
using namespace std;

#define ll long long
int main(){
    ll t,n,arr[100009];
    while(cin>>n && n){
        for(ll i=1;i<=n;i++)cin>>arr[i];
        char *a="ambiguous\n";
        for(ll i=0;i<n;i++)
            if(arr[arr[i]]!=i){
                a="not ambiguous\n";
                break;
            }
        cout<<a;
    }
    return 0;
}
