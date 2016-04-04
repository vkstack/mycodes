#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct SegNode{
  long bestL,bestR,maxSum,total;
  void merge(SegNode& left,SegNode& right){
    total=left.total+right.total;
    bestL=max(left.bestL,left.total+right.bestL);
    bestR=max(right.bestR,right.total+left.bestR);
    maxSum=max(bestL,max(bestR,max(left.maxSum,max(right.maxSum,left.bestR+right.bestL))));
  }
  void setValue(long val){
    bestL=bestR=maxSum=total=val;
  }
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
    nodes=new SegNode[sz+10];
    BuildTree(arr,1,0,n-1);
  }
  ~Tree(){
    delete[] nodes;
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

  V Query(int lo, int hi) {
    // cout<<"started Querying\n";
    SegNode result = Query(1, 0, n-1, lo, hi);
  	return result.maxSum;
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
  void update(int ind,T value){
    update(1,0,n-1,ind,value);
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

int main(){
    // std::ios_base::sync_with_stdio (false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int l,r,n;
    long a[50009],q;
    scanf("%d",&n);
    // cin>>n;
    for(int i=0;i<n;i++){
      scanf("%ld",a+i);
      //cin>>a[i];
    }
    Tree<long,long> tree(a,n);
    // for(int i=1;i<=tree.sz;i++)
    //   cout<<tree.nodes[i].maxSum<<" ";
    // cout<<"\n";
    SegNode res;
    scanf("%ld",&q);
    // cin>>q;
    // while(q--){
    //   scanf("%d%d",&l,&r);
    //   // cin>>l>>r;
    //   l--;r--;
    //   printf("%ld\n",tree.Query(l,r));
    // }
    int f;
    while(q--){
      cin>>f>>l>>r;
      if(f==0)
        tree.update(l-1,r);
      else
        printf("%ld\n",tree.Query(l-1,r-1));
    }
    return 0;
}
