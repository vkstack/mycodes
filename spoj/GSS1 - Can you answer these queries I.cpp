#include<iostream>
using namespace std;

int main()}{
    long n,a[50009],c[50009],l[50009];
    c[0]=0;
    l[0]=0;
    for(i=1;i<=n;i++){
        cin>>a[i];
        c[i]=c[i-1]+a[i];
        l[i]=0
    }
    long mxk=1;
    for(i=1;i<=n;i++){
        if(c[i]>c[mxk]){
            l[i]=0;
            mxk=i;
        }
        else
            l[i]=mxk;
    }
}
