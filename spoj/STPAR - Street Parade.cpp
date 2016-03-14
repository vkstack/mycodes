    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int main(){
        long long n;
        while(cin>>n && n){
            vector<long long> st,v;
            st.push_back(1000000000000000009);
            long long i=0,top,x;
            for(;i<n;i++){
                cin>>x;
                top=st.back();
                while(top<x){
                    v.push_back(top);
                    st.pop_back();
                    top=st.back();
                }
                st.push_back(x);
            }
//            for(long long j=0;j<st.size();j++)
//                cout<<st[j]<<" ";
//            cout<<"\n";
//            for(long long j=0;j<v.size();j++)
//                cout<<v[j]<<" ";
//            cout<<"\n";
            long long fl=1;
            for(long long i=0,len=st.size();i<len-1;i++){
                if(st[i]<st[i+1])
                    fl=0;
            }
            for(long long i=0,len=v.size();i<len-1;i++){
                if(v[i]>v[i+1])
                    fl=0;
            }
            if(fl)
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
        return 0;
    }
