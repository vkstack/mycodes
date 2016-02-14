#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long MIN(long a,long b){
    return a>b?b:a;
}
long ABS(long a){
    return a<0?-a:a;
}
int main(){
	long t,m,n,x;
	vector<long> M,N;
	cin>>t;
	long i,j,ans;
	while(t--){
		cin>>m;
		for(long i=0;i<m&&cin>>x;i++)M.push_back(x);
		cin>>n;
		for(long i=0;i<n&&cin>>x;i++)N.push_back(x);
		sort(M.begin(),M.end());
		sort(N.begin(),N.end());
		i=j=0;
		ans=abs(M[0]-N[0]);
		while(i<m && j<n){
			ans=MIN(ans,ABS(M[i]-N[j]));
			if(M[i]==N[j])
				break;
			if(M[i]<N[j])
				i++;
			else
				j++;
		}
		cout<<ans<<"\n";
		M.clear();
		N.clear();
	}
    return 0;
}