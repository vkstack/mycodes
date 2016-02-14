    #include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    #include<vector>
    #include<limits>
    #include<cmath>
    #include<map>
    using namespace std;

    #define FOR(i,N) for(int i=0;i<(N);i++)
    //vector<string> split(string str, char delimiter) {
    //  vector<string> internal;
    //  stringstream ss(str); // Turn the string into a stream.
    //  string tok;
    //
    //  while(getline(ss, tok, delimiter)) {
    //    internal.push_back(tok);
    //  }
    //  return internal;
    //}
    string removeChar(string s,char c){
        string tmp="";
        int i=0;
        while(s[i]){
            if(s[i]!=c)
                tmp+=s[i];
            i++;
        }
        return tmp;
    }
    bool contains(string s,string var){
        return s.find(var);
    }
    string operate(string a,string b,char op){
        long A=0,B=0,i=0;
        while(a[i]){
            A=A*10+a[i]-'0';
            i++;
        }
        i=0;
        while(b[i]){
            B=B*10+b[i]-'0';
            i++;
        }
        if(op=='-')
            A-=B;
        else
            A+=B;
        a="";
        string tmp;
        while(A){
            tmp=('0'+A%10);
            a=tmp+a;
            A/=10;
        }
        return a;
    }
    int conv(string s)
    {
        int ret=0;
        FOR(i,s.length())
        {
            if(!isdigit(s[i])) return -1;
            ret=ret*10+(s[i]-'0');
        }
        return ret;
    }
    int main(){
        string t;
        int T=0,i=0;
        cin>>T;
        string s,a,b,c,var="machula";
        char pl,eq;
        while(T--){
            cin>>a>>pl>>b>>eq>>c;
            int A,B,C;
            A=conv(a);
            B=conv(b);
            C=conv(c);
            if(A<0) A=C-B;
            if(B<0) B=C-A;
            if(C<0) C=A+B;
            cout<<A<<" + "<<B<<" = "<<C<<"\n";
        }
        return 0;
    }
