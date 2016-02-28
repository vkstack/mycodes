#include<iostream>
#include<cstdio>
using namespace std;

#define ll long long
int main(){
    ll x;
    cin>>x;
    if(x==0 || x&(x-1)==0)
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
    return 0;
}

