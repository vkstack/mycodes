#include<iostream>
#include<cstring>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    int t,a;
    char s1[1001];
    cin>>t;
    while(t--){
        cin>>a>>s1;
        if(a==0){
            cout<<s1<<"\n";
            continue;
        }
        int i,l=strlen(s1),rem=0;
        for(i=0;i<l;i++)
            rem=(rem*10+(s1[i]-'0'))%a;
        cout<<gcd(a,rem)<<"\n";
    }
    return 0;
}
