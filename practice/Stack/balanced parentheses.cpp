#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    map<char,char>mp;
    mp['}']='{';
    mp[']']='[';
    mp[')']='(';
    char c[1000];
    int t;
    cin>>t;
    while(t--){
        cin>>c;
        vector<char> st;
        int i=0,flag=1;
        while(c[i]){
            if(mp[c[i]]){
                if(mp[c[i]]!=st.back()){
                    flag=0;
                    break;
                }
                st.pop_back();
            }
            else
                st.push_back(c[i]);
        }
        if(flag)
            cout<<"Balanced\n";
        else
            cout<<"Not Balanced\n";
    }
    return 0;
}

