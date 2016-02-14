#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long a,b,c;
    while(cin>>a>>b>>c &&(abs(a)+abs(b)+abs(c))){
        if(2*b==a+c)
            cout<<"AP "<<c+c-b<<"\n";
        else
            cout<<"GP "<<(c*c/b)<<"\n";
    }
    return 0;
}
