#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char ch[1000];
    int n;
    while(cin>>n && n){
        cin>>ch;
        int len=strlen(ch),rows;
        rows=len/n;
        int i,j;
        for(j=0;j<n;j++)
            for(i=0;i<rows;i++){
                if(i%2==0)
                    cout<<ch[i*n+j];
                else
                    cout<<ch[(i+1)*n-j-1];
            }
        cout<<"\n";
    }
}
