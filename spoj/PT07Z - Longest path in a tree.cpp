#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

#define ll long long
ll n,u,v,rm,fmost;
vector<ll>adj[100000+5];
ll dist[100009];

void bfs(ll src){
    bool vis[n];
    for(ll i=0;i<n;i++){
        vis[i]=0;
        dist[i]=0;
    }
    list<ll>q;
    q.push_back(src);
    vis[src]=1;
    while(!q.empty()){
        ll top=q.back();
        q.pop_back();
        for(ll i=0,len=adj[top].size();i<len;i++)
            if(!vis[adj[top][i]]){
                dist[adj[top][i]]=dist[top]+1;
                vis[adj[top][i]]=1;
                q.push_back(adj[top][i]);
            }
    }
    rm=0;
    for(ll i=0;i<n;i++){
        rm=rm>dist[i]?rm:dist[i];
        if(rm==dist[i]) fmost=i;
    }
};

int main(){
    scanf("%lld",&n);
    for(ll i=0;i<n-1;i++){
        scanf("%lld%lld",&u,&v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    bfs(u-1);
    bfs(fmost);
    printf("%lld\n",rm);
    return 0;
}
