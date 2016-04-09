#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;


struct SegNode{
  long max1,max2;
  void setValue(long x){
    max2=x;
    max1=-1;
  }
  void merge(SegNode& left,SegNode& right){
    max2=max(left.max2,right.max2);
    max1=max(left.max1,max(right.max1,min(left.max2,right.max2)));
  }
  long getVal(){
    return max1+max2;
  };
};
int getmid(int x,int y){ return (x+y)/2;}

template <class T,class V>
class Tree{
public:
  SegNode *nodes;
  int n;
  int sz=1;
  Tree(T arr[],int x){
    n=x;
    for(;sz<n;sz<<=1);
    sz<<=1;
    nodes=new SegNode[sz];
    BuildTree(arr,1,0,n-1);
  }
  ~Tree(){
    delete[] nodes;
  }
  void update(int ind,T value){
    update(1,0,n-1,ind,value);
  }
  void BuildTree(T arr[],int stin,int ss,int se){
    if(ss==se){
      nodes[stin].setValue(arr[ss]);
      return;
    }
    int mid=getmid(ss,se),left=stin<<1;
    int right=left+1;
    BuildTree(arr,left,ss,mid);
    BuildTree(arr,right,mid+1,se);
    nodes[stin].merge(nodes[left],nodes[right]);
  }
  void update(int stin,int ss,int se,int i,T value){
    if(ss==se){
      nodes[stin].setValue(value);
      return;
    }
    int mid=getmid(ss,se);
    if(i<=mid)
      update(2*stin,ss,mid,i,value);
    else
      update(2*stin+1,mid+1,se,i,value);
    nodes[stin].merge(nodes[2*stin],nodes[2*stin+1]);
  }
};
  V Query(int lo, int hi) {

    // cout<<"started Querying\n";
    SegNode result = Query(1, 0, n-1, lo, hi);
  	return result.getVal();
  }
  SegNode Query(int stin,int ss,int se,int qs,int qe){
    // cout<<"Querying for"<<ss<<"--"<<se<<"\n";
    if(ss==qs && se==qe)
      return nodes[stin];
    int mid=(ss+se)/2;
    if(qs>mid)
      return Query(2*stin+1,mid+1,se,qs,qe);
    if(qe<=mid)
      return Query(2*stin,ss,mid,qs,qe);
    SegNode leftres=Query(2*stin,ss,mid,qs,mid);
    SegNode rightres=Query(2*stin+1,mid+1,se,mid+1,qe),res;
    res.merge(leftres,rightres);
    return res;
  }

int main(){
    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l,r,n;
    long q,a[30009];
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    Tree<long,long> tree(a,n);
    // for(int i=1;i<=tree.sz;i++)
    //   cout<<tree.nodes[i].max2<<" ";
    // cout<<"\n";
    SegNode res;
    cin>>q;
    char c;
    while(q--){
      cin>>c>>l>>r;
      if(c=='U'){
        tree.update(l-1,r);
      }
      else
        printf("%ld\n",tree.Query(l-1,r-1));
    }
    return 0;
}
