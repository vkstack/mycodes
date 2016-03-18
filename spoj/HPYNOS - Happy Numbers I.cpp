#include<iostream>
using namespace std;

int getsum(long long n){
//    cout<<n<<"\n";
    int tmp=0;
    while(n){
        int x=n%10;
        tmp+=x*x;
        n/=10;
    }
    return tmp;
}
int main(){
    long long n,a[1000];
    for(int i=0;i<1000;i++)a[i]=0;
    cin>>n;
    int i=1,tmp,ans=-1;
    if(n==1)
        cout<<0;
    else{
        while((n=getsum(n))>1){
            i++;
            if(n<1000 && a[n]==1){
                ans=-2;
                break;
            }
            else if(n<1000)
                a[n]=1;
        }
        if(ans==-2)
            cout<<-1;
        else
            cout<<i;
    }
    return 0;
}
