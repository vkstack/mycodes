#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t,a,b,A[100009],B[100009];
    cin>>t;
    while(t--){
        cin>>a>>b;
        for(int i=0;i<a;i++)
            cin>>A[i];
        for(int i=0;i<b;i++)
            cin>>B[i];
        sort(A,A+a);
        sort(B,B+b);
        int i=0,j=0;
        while(a && b){
            if(A[i]<B[j]){
                i++;
                a--;
            }
            else{
                j++;
                b--;
            }
        }
        if(a)
            cout<<"Godzilla\n";
        else
            cout<<"MechaGodzilla\n";
    }
    return 0;
}
