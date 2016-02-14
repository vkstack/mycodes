#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    long n,x;
    vector<long> v;
    while(cin>>n && n!=-1){
        long total=0,ans=0;
        v.clear();
        for(long i=0;i<n;i++){
            cin>>x;
            total+=x;
            v.push_back(x);
        }
//        cout<<total<<"   total\n";
        if(total%n==0){
            long avg=total/n;
            for(long i=0;i<n;i++)
                ans+=abs(v[i]-avg);
            cout<<ans/2<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
    return 0;
}
