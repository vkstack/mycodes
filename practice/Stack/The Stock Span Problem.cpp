#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<long> st;
    long t,n,arr[100000],b[100000];
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
            while(!st.empty()&& arr[st.back()]<=arr[i])
                st.pop_back();
            b[i]=st.empty()?i+1:(i-st.back());
            st.push_back(i);
        }
    }
    return 0;
}
