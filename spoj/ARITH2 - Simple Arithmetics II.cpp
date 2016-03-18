#include<iostream>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long a,res=-1;
        char o;
        cin>>a;
        res=a;
        while(cin>>o && o!='='){
            cin>>a;
            if(o=='+')
                res+=a;
            else if(o=='-')
                res-=a;
            else if(o=='/')
                res/=a;
            else if(o=='*')
                res*=a;
            else if(o=='%')
                res%=a;
        }
        cout<<res<<"\n";
    }
    return 0;
}
