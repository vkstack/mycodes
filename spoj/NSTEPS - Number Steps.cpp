#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


int main(){
    int t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x==y||x-y==2){
            if(x==y){
                if(x%2)
                    cout<<x+y-1;
                else
                    cout<<x+y;
            }
            else{
                if(x%2)
                    cout<<x+y-1;
                else
                    cout<<x+y;
            }
        }
        else
            cout<<"No Number";
        cout<<"\n";
    }
    return 0;
}
