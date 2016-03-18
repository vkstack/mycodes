#include<iostream>
using namespace std;
int main(){
    long long t,n;
    cin>>t;
    while(t--){
        cin>>n>>n;
        if(n==0)
            cout<<"Airborne wins.\n";
        else
            cout<<"Pagfloyd wins.\n";
    }
    return 0;
}
