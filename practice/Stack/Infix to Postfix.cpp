#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    map<char,int>prec;
    prec['^']=3;
    prec['*']=2;
    prec['/']=2;
    prec['+']=1;
    prec['-']=1;
    char c[1000];
    int t;
    cin>>t;
    while(t--){
        cin>>c;
        vector<char> v;
        int i=0;
        while(c[i]){
            if(('a'<=c[i]&&c[i]<='z')||('A'<=c[i]&&c[i]<='Z'))
                cout<<c[i];
            else if(c[i]=='(')
                v.push_back(c[i]);
            else if(c[i]==')'){
                while(!v.empty()&& v.back()!='('){
                    cout<<v.back();
                    v.pop_back();
                }
                v.pop_back();
            }
            else{
                    while(!v.empty() && prec[c[i]]<=prec[v.back()]){
                        cout<<v.back();
                        v.pop_back();
                    }
                    v.push_back(c[i]);
            }
            i++;
        }
        while(!v.empty()){
            cout<<v.back();
            v.pop_back();
        }
        cout<<"\n";
    }
    return 0;
}
