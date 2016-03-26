#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    long t,n,a[100000],b[100000];
    cin>>t;
    while(t--){
        cin>>c;
        vector<long>st;
        long i=0;
        for(;i<n;i++){
            cin>>a[i];
            if(st.empty()||a[st.back()]>=a[i])
                st.push_back(i);
            else{
                while(!st.empty()&& a[st.back()]<a[i]){
                    b[st.back()]=a[i];
                    st.pop_back();
                }
            }
        }
        while(!st.empty()){
            b[st.back()]=-1;
            st.pop_back();
        }
    }
    return 0;
}


