#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    long long n,h[100009];
    while(cin>>n && n){
        vector<long long>st;
        long long i,ans=0,atop;
        for(i=0;i<n;i++)
            cin>>h[i];
        for(i=0;i<n;){
            if(st.empty()||h[st.back()]<=h[i])
                st.push_back(i++);
            else{
                long long top=st.back();
                st.pop_back();
                atop=h[top]*(st.empty()?i:i-st.back()-1);
                ans=max(ans,atop);
            }
        }
        while(!st.empty()){
            long long top=st.back();
            st.pop_back();
            atop=h[top]*(st.empty()?i:i-st.back()-1);
            ans=max(ans,atop);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
