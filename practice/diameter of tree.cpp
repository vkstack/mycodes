#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
struct node{
    int d;
    node *l,*r;
};
long max(long a,long b){ return a>b?a:b;}
long height(node *h){
    if(!h) return 0;
    return 1+max(height(h->l),height(h->r));
}

node* newNode(int d){
    node *ptr=new node;
    ptr->l=ptr->r=NULL;
    ptr->d=d;
    return ptr;
}
long diameter(node *h){
    if(!h)
        return 0;
    return max(1+height(h->l)+height(h->r),max(diameter(h->l),diameter(h->r)));
}
void deleteT(node *h){
    if(!h)
        return;
    deleteT(h->l);
    deleteT(h->r);
    free(h);
}

struct pair{
    long first,second;
};

