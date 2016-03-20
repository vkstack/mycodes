#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long

int main(){
    ll a,d;
    vector<ll>v1,v2;
    while(cin>>a){
        cin>>d;
        if(a==0 && d==0)
            return 0;
        for(int i=0,x;i<a;i++){
            cin>>x;
            v1.push_back(x);
        }
        for(int i=0,x;i<d;i++){
            cin>>x;
            v2.push_back(x);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1[0]<v2[1])
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}
