#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct SegNode{
  long openBrac,closeBrac;
  void merge(SegNode& left,SegNode& right){
    int tmp=min(left.openBrac,right.closeBrac);
    openBrac=left.openBrac+right.openBrac-tmp;
    closeBrac=left.closeBrac+right.closeBrac-tmp;
  }
  void setValue(char ch){
    if (ch == '(')
      openBrac = 1, closeBrac = 0;
    else
      openBrac = 0, closeBrac = 1;
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
  	return result.openBrac==0 && result.closeBrac==0;
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
    long q;
    char a[30009];
    for (int t = 1; t <= 10; ++t) {
    	cout<<"Test "<<t<<":\n";
        cin>>n;
        cin>>a;
        Tree<char,bool> tree(a,n);
        for(int i=1;i<=tree.sz;i++)
          cout<<tree.nodes[i].openBrac<<" ";
        cout<<"\n";
        SegNode res;
        scanf("%ld",&q);
        int f;
        while(q--){
          cin>>f;
          if(f!=0){
          	l=f;
            l--;
            a[l]=( a[l] == '(' ) ? ')' : '(';
            tree.update(l,a[l]);
          }
          else
            printf("%s\n",tree.Query(0,n-1)?"YES":"NO");
        }
    }
    return 0;
}
