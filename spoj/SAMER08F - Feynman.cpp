#include<iostream>
using namespace std;
int main(){
    long n;
    while(cin>>n&&n)
        cout<<((n*(n+1)*(2*n+1))/6)<<"\n";
    return 0;
}
