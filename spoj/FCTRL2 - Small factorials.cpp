#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class bigInt{
public:
    char val[3001];
    bigInt(){}
    void scanit(){
        cin>>(this->val);
    }
    void assignit(char c[]){
        strcpy(this->val,c);
    }
    bigInt operator*(const bigInt& b){
        bigInt a= *this;
        int al=strlen(a.val),bl=strlen(b.val),i,j,k,x,y,z,carry=0,pos=0;
        char result[10001];
        for(i=0;i<10001;i++)result[i]='0';
        for(i=al-1;i>=0;i--){
            x=a.val[i]-'0';
            k=pos++;
            for(j=bl-1;j>=0;j--){
                y=b.val[j]-'0';
                z=result[k]-'0'+(x*y)+carry;
                carry=z/10;
                result[k++]='0'+z%10;
            }
            while(carry){
                result[k++]+=carry%10;
                carry/=10;
            }
        }
        bigInt ans;
        j=0,i=al*bl+al;
        while(result[i]=='0')
            i--;
        for(;i>=0;i--)
            ans.val[j++]=result[i];
        ans.val[j]='\0';
        return ans;
    }
};
 int main(){
    bigInt a,ans;
    int t,n;
    cin>>t;
    while(t--){
        ans.assignit("1");
        cin>>n;
        for(int i=2;i<=n;i++){
            char c[100];
            int ln=1+floor(log10(i)),x=i;
            c[ln]='\0';
            while(ln--){
                c[ln]='0'+x%10;
                x/=10;
            }
            a.assignit(c);
            ans=ans*a;
        }
        cout<<ans.val<<"\n";
    }
    return 0;
 }
