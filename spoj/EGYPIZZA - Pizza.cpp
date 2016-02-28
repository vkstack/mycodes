#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,j,k,a,b;
    int a1=0;
    int a2=0;
    int a3=0;
    cin>>n;
    char ch;
    for(int i=0;i<n;i++){
        cin>>a>>ch>>b;
        if(a==3) a3++;
        else if(b==2)a2++;
        else if(b==4)a1++;
    }
    long sum=a3;
    a1-=a3;
    sum+=a2/2;
    a2%=2;
    if(a2){
        sum++;
        a1-=2;
    }
    if(a1>0)
        sum+=ceil(a1/4.0);
    cout<<sum+1;
    return 0;
}
