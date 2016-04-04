#include<iostream>
#include<cmath>

template <typename T>
T TreeBuild(T *st,T arr[],long ss,long se,long si){
  if(ss=ee)
    return st[si]=arr[ss];
  long mid=ss+(se-ss)/2;
  return st[si]=TreeBuild(st,arr,ss,mid,2*si+1)
                +TreeBuild(st,arr,mid+1,2*si+2);
}


template <typename T>
T merge(T a,T b){

}
template <typename T>
T constructTree(T arr[],long n){
  long sz=1;
  for(;sz<n;sz<<=1);
  T *st= new T[sz<<1];
  TreeBuild(st,arr,0,n-1,0);
  return st;
}

template <typename T>
T rangeQuery(T *st,long ss,long se,long qs,long se,long si){
  if(ss==qs && se==qe) return st[si];
  if(qs>se || qe<ss)   return 0;
  long mid=ss+(se-ss)/2;
  return rangeQuery(st,ss,mid,qs,qe,2*si+1)
          +rangeQuery(st,mid+1,se,qs,qe,2*si+2);
}

template <typename T>
void update(T *st,long ss,long se,long i,T diff,int si){
  if(i<ss||i>se)
      return;
  st[si]+=diff;
  if(ss!=se){
    long mid=ss+(se-ss)/2;

  }
}
