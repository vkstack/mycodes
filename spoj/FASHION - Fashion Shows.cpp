#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,x,ans=0;
        cin>>n;
        vector<int> M,W;
        M.clear();
        W.clear();
        for(i=0;i<n;i++)cin>>x,M.push_back(x);
        for(i=0;i<n;i++)cin>>x,W.push_back(x);
        sort(M.begin(),M.end());
        sort(W.begin(),W.end());
        for(i=0;i<n;i++)
            ans+=M[i]*W[i];
        cout<<ans<<"\n";
    }
}

