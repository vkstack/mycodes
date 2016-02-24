#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define ll long long
#define inf 100000000000000000

vector<pair<ll,ll> >*adj=new vector<pair<ll,ll> >[10002];
ll t,n,nbr,ind,r,heapsize;
bool isinheap[10002];
ll pos[10002];
vector<ll> shortestPath;

template<class T> void swap(T *a,T *b){
    ll tmppos=pos[(*a).first];
    pos[(*a).first]=pos[(*b).first];
    pos[(*b).first]=tmppos;
    T tmp=*a;
    *a=*b;
    *b=tmp;
}
void minHeapify(vector<pair<ll,ll> >*heapref,ll ind){
    ll small=ind,left=2*ind+1,right=2*ind+2;
    if(left<heapsize && (*heapref)[left].second<(*heapref)[small].second)
        small=left;
    if(right<heapsize && (*heapref)[right].second<(*heapref)[small].second)
        small=right;
    if(small!=ind){
        swap(&((*heapref)[small]),&((*heapref)[ind]));
        minHeapify(heapref,small);
    }
}

pair<ll,ll> extractMin(vector<pair<ll,ll> > *heapref){
    pair<ll,ll>root=*(*heapref).begin();
    (*heapref)[0]=(*heapref)[heapsize-1];
    pos[(*heapref)[0].first]=0;
    (*heapref).pop_back();
    isinheap[root.first]=0;
    minHeapify(heapref,0);
    heapsize--;
    return root;
}
void decreaseKey(vector<pair<ll,ll> > *heapref,ll v,ll newval){
    ll i=pos[v];
    (*heapref)[i].second=newval;
    while(i && (*heapref)[i].second<(*heapref)[(i-1)/2].second){
        swap(&((*heapref)[i]),&((*heapref)[(i-1)/2]));
        i=(i-1)/2;
    }
}

ll djikshtra(ll src,ll dst,vector<pair<ll,ll> > *heapref){
    ll dist[n];
    (*heapref).push_back(make_pair(src,0));
    pos[src]=0;
    for(ll i=0,j=1;i<n ;i++){
        isinheap[i]=true;
        if(i!=src){
            pos[i]=j++;
            dist[i]=inf;
            (*heapref).push_back(make_pair(i,dist[i]));
        }
    }
    dist[src]=0;
    while(!(*heapref).empty()){
        pair<ll,ll> pr=extractMin(heapref);
        ll u=pr.first;
        vector<pair<ll,ll> >::iterator it=adj[u].begin();
        while(it!=adj[u].end()){
            ll v=(*it).first;
            if(isinheap[v] && dist[u]!=inf && (*it).second + dist[u] < dist[v]){
                dist[v]=(*it).second + dist[u];
                decreaseKey(heapref,v,dist[v]);
            }
            it++;
        }
    }
    return dist[dst];
}
int main(){
    string city,src,dstn;
    cin>>t;
    map<string,ll>city2index;
    while(t--){
        cin>>n;
        ll i,j,k;
        vector<pair<ll,ll> >heap;
        for(i=0;i<n && cin>>city>>r;i++){
            city2index[city]=i;
            while(r--){
                ll distance;
                cin>>nbr>>distance;
                adj[i].push_back(make_pair(nbr-1,distance));
            }
        }
        cin>>r;
        while(r--){
            heapsize=n;
            heap.clear();
            cin>>src>>dstn;
            cout<<djikshtra(city2index[src],city2index[dstn],&heap)<<"\n";
        }
        for(ll i=0;i<n;i++)
            adj[i].clear();
    }
    return 0;
}
