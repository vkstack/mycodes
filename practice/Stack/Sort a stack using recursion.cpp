#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<long>st;

void sortedInsert(long item){
    if(st.size()==0|| st.back()<item)
        st.push_back(item);
    else{
        long x=st.back();
        st.pop_back();
        sortedInsert(item);
        st.push_back(x);
    }
}

void sortStack(){
    long top;
    if(st.size()){
        top=st.back();
        st.pop_back();
        sortStack();
        sortedInsert(top);
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
        sortStack();
        cout<<"\n";
        for(i=0;i<n;i++)
            cout<<st[i]<<" ";
    }
    return 0;
}

