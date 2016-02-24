#include<iostream>
#include<climits>
using namespace std;

#define ll long long

void swap(ll *a,ll *b){ (*a)^=(*b);(*b)^=(*a);(*a)^=(*b);}
class minHeap{
    ll cap,siz, *arr;
public:
    minHeap(ll);
    void minHeapify(ll cap);
    ll parent(ll x){ return  (x-1)>>1;}
    ll lchild(ll x){ return 2*x+1;}
    ll rchild(ll x){ return 2*x+2;}
    ll getMin(){ return arr[0];}
    ll extractMin();
    void decreaseKey(ll i,ll new_val);
    void deleteKey(ll i);
    void insertKey(ll k);
};
minHeap::minHeap(ll cap){
    this->cap=cap;
    siz=0;
    arr=new ll[cap];
}
void minHeap::insertKey(ll k){
    if(siz==cap){
        cout<<"Overflow\n";
        return;
    }
    arr[siz++]=k;
    ll i=siz-1;
    while(i && arr[parent(i)]>ar[i]){
        swap(arr+i,arr+parent(i));
        i=parent(i);
    }
}
void minHeap::decreaseKey(ll i,ll new_val){
    arr[i]=new_val;
    while(i && arr[parent(i)]>ar[i]){
        swap(arr+i,arr+parent(i));
        i=parent(i);
    }
}

void minHeap::extractMin(){
    if(siz==0)
        return INT_MAX;
    if(siz=1)
        return arr[0];
    ll root=arr[0];
    siz--;
    minHeapify(0);
    return root;
}

void minHeap::deleteKey(ll i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

void minHeap::minHeapify(int i){
    ll l=left(i),r=right(i),smallest=i;
    if(l<siz && arr[l]<arr[smallest])
        smallest=l;
    if(r<siz && arr[r]<arr[smallest])
        smallest=r;
    if(smallest!=i){
        swap(arr+smallest,arr+i);
        minHeapify(smallest);
    }
}
