#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int cordinat2int(pair<int,int>p){
  return p.first*8+p.second;
}
bool isvalid(pair<int,int>p){
  return p.first<8 && p.first>=0 && p.second <8 &&p.second>=0;
}
int bfs(pair<int,int> src,pair<int,int> dst){
  bool vis[100]={false};
  int moves[100]={0};
  vis[cordinat2int(src)]=true;
  list<pair<int,int> > list;
  list.push_back(src);
  while(!list.empty()){
    src=list.front();
    list.pop_front();
    if(src == dst){
      list.clear();
      return moves[cordinat2int(dst)];
    }
    vector<pair<int,int> >expansion;
    expansion.push_back(make_pair(src.first+2,src.second+1));
    expansion.push_back(make_pair(src.first+1,src.second+2));
    expansion.push_back(make_pair(src.first-2,src.second+1));
    expansion.push_back(make_pair(src.first-1,src.second+2));
    expansion.push_back(make_pair(src.first+2,src.second-1));
    expansion.push_back(make_pair(src.first+1,src.second-2));
    expansion.push_back(make_pair(src.first-2,src.second-1));
    expansion.push_back(make_pair(src.first-1,src.second-2));
    for(vector<pair<int,int> >::iterator it = expansion.begin();it!=expansion.end();it++){
      int x;
      pair<int,int> a1= *it;
      if(isvalid(a1) && !vis[(x=cordinat2int(a1))]){
        list.push_back(a1);
        moves[x] = moves[cordinat2int(src)]+1;
        vis[x] = true;
      }
    }
    expansion.clear();
  }
}

int main(){
  short int t;
  cin>>t;
  string a;
  while(t--){
    cin>>a;
    pair<int,int> src =make_pair(a[0]-'a',a[1]-'1');
    cin>>a;
    pair<int,int> dst =make_pair(a[0]-'a',a[1]-'1');
    cout<<bfs(src,dst)<<"\n";
  }
  return 0;
}
