#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

int main(){
    vector<char>st;
    char c[100009];
    int t,n;
    cin>>t;
    while(t--){
        int i=0;
        st.push_back(-1);
        cin>>c;
        int ans=0;
        while(c[i]){
            if(c[i]=='(')
                st.push_back(i);
            else{
                st.pop_back();
                if(!st.empty())
                    ans=max(ans,i-st.back());
                else
                    st.push_back(i);
            }
            i++;
        }
        cout<<ans<<"\n";
        st.clear();
    }
    return 0;
}
