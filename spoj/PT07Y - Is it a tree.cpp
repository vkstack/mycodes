#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
ll n,u,v;
vector<ll>adj[100000+5];
bool isTree;
bool vis[100000+5];
void bfs(ll src,ll par=-1){
    vis[src]=1;
    for(ll i=0,len=adj[src].size();i<len;i++){
        if(!vis[adj[src][i]])
            bfs(adj[src][i],src);
        else if(adj[src][i]!=par){
            isTree=0;
            return;
        }
    }
};
int main(){
    isTree=1;
    for(ll i=0;i<100005;i++)
        vis[i]=0;
    ll m;
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<m;i++){
        scanf("%lld%lld",&u,&v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    if(m<n){
        bfs(0);
        for(ll i=0;i<n;i++)
            if(!vis[i])
                isTree=0;
        if(isTree)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else
        cout<<"NO\n";
    return 0;
}
