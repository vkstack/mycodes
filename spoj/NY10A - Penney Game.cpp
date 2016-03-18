#include<iostream>
using namespace std;

 int getval(int t[]){
    int a=0;
    if(t[0]==1)
        a=+4;
    if(t[1]==1)
        a+=2;
    if(t[2]==1)
        a+=1;
    return a;
}

int main(){
    int t,n;
    cin>>t;
    char a[50];
    while(t--){
        int b[8];
        cin>>n>>a;
        cout<<n<<" ";
        for(int i=0;i<8;i++)b[i]=0;
        for(int i=0;i<38;i++){
            int tt[3];
            for(int j=0;j<3;j++){
                if(a[i+j]=='H')
                    tt[j]=0;
                else
                    tt[j]=1;
            }
            b[getval(tt)]++;
        }
        for(int i=0;i<8;i++)cout<<b[7-i]<<" ";
        cout<<"\n";
    }
    return 0;
}
