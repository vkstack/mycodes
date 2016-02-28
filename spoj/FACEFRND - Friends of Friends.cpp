#include<iostream>
using namespace std;

int main(){
    long n,arr[10000]={0};
    cin>>n;
    while(n--){
        long x,nn,y;
        cin>>x>>nn;
        arr[x]=-1;
        while(nn--){
            cin>>y;
            if(arr[y]==0)
                arr[y]=1;
        }
    }
    long ans=0;
    for(long i=0;i<10000;i++)
        if(arr[i]==1)
            ans++;
    cout<<ans<<"\n";
    return 0;
}
