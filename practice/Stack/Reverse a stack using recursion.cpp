#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<long>st;

void insertAtBttom(long item){
    if(st.size()==0)
        st.push_back(item);
    else{
        long x=st.back();
        st.pop_back();
        insertAtBttom(item);
        st.push_back(x);
    }
}

void rev(){
    long top;
    if(st.size()){
        top=st.back();
        st.pop_back();
        rev();
        insertAtBttom(top);
    }
}

int main(){
    long t,n;
    cin>>t;
    while(t--){
        long i=0,x;
        cin>>n;
        for(;i<n;i++){
            cin>>x;
            st.push_back(x);
        }
        for(i=0;i<n;i++)
            cout<<st[i]<<" ";
        rev();
        cout<<"\n";
        for(i=0;i<n;i++)
            cout<<st[i]<<" ";
    }
    return 0;
}
