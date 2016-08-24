#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
#include<cmath>
using namespace std;

int m,n;
bool bfs(pair<int,int>s, pair<int,int>c1, pair<int,int>c2){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(i==1 || i==n || j==1||j==m){
        int dc1=abs(i-c1.first)+abs(j-c1.second);
        int dc2=abs(i-c2.first)+abs(j-c2.second);
        int ds=abs(i-s.first)+abs(j-s.second);
        if(ds<min(dc1,dc2)){
          return true;
        }
      }
    }
  }
  return false;
}
int main(){
  int t;
  cin>>n>>m>>t;
  while(t--){
    int x,y;
    pair<int,int>s,c1,c2;
    cin>>x>>y;
    s=make_pair(x,y);

    cin>>x>>y;
    c1=make_pair(x,y);

    cin>>x>>y;
    c2=make_pair(x,y);
    cout<<(bfs(s,c1,c2)?"YES\n":"NO\n");
  }
  return 0;
}
