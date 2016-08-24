#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

list<long> lst;
long bfs(long s,long g,long f,long u,long d){
  bool vis[1000000+10] = {false};
  long dist[1000000+10] = {0};
  vis[s]=true;
  lst.push_back(s);
  while(!lst.empty()){
    s=lst.front();
    lst.pop_front();
    long tu,td;
    if(s==g){
      return dist[g];
    }
    if((tu=s+u)<=f && !vis[tu]){
      lst.push_back(tu);
      vis[tu]=true;
      dist[tu]=dist[s]+1;
    }
    if((td=s-d)>0 && !vis[td]){
      lst.push_back(td);
      vis[td]=true;
      dist[td]=dist[s]+1;
    }
  }
  lst.clear();
  return -1;
}

int main(){
  long s,f,g,u,d,ans;
  cin>>f>>s>>g>>u>>d;
  ans=bfs(s,g,f,u,d);
  if(ans!=-1)
    cout<<ans;
  else
    cout<<"use the stairs";
  return 0;
}
