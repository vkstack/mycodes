#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long


int main(){
    long n,u,v;
    cin>>n;
    vector<long>adj[n+5];
    pair branch[n];
    map<long,long> mp;
    for(long i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
