#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    map<long,bool>mp;
    long x=1,i=1;
    mp[1]=1;
    while(x<=1000000000){
        x+=6*i;
        i++;
        mp[x]=1;
    }
//    cout<<mp.size();
    long n;
    while(cin>>n && n!=-1){
        if(mp[n])
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}
