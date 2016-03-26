#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int t,a[200][200],b[200][200],n,m;
vector<pair<int,int> >wt;
queue<pair<int,int> >st;

void dfs(pair<int,int>p){
    int x=p.first,y=p.second;
    st.push(p);
    b[x][y]=0;
    while(!st.empty()){
        pair<int,int>pr=st.front();
        st.pop();
        int x1=pr.first,y1=pr.second,d=b[x1][y1]+1;

        if(x1-1>0 && d<b[x1-1][y1]){
            st.push(make_pair(x1-1,y1));
            b[x1-1][y1]=d;
        }
        if(x1+1<=n && d<b[x1+1][y1]){
            st.push(make_pair(x1+1,y1));
            b[x1+1][y1]=d;
        }
        if(y1-1>0 && d<b[x1][y1-1]){
            st.push(make_pair(x1,y1-1));
            b[x1][y1-1]=d;
        }
        if(y1+1<=m && d<b[x1][y1+1]){
            st.push(make_pair(x1,y1+1));
            b[x1][y1+1]=d;
        }
    }
}

int main(){
    char c[200];
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>c;
            for(int j=1;j<=m;j++){
                a[i][j]=c[j-1]-'0';
                if(a[i][j]==1){
                    wt.push_back(make_pair(i,j));
                    b[i][j]=0;
                }
                else
                    b[i][j]=100000;
            }
        }
        while(!wt.empty()){
            dfs(wt.back());
            wt.pop_back();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
