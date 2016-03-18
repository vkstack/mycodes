#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    long double r;
    scanf("%d",&t);
    int i=0;
    while(t--){
        i++;
        scanf("%llf",&r);
        printf("Case %d: %.2llf\n",i,4*r*r+0.25);
    }
    return 0;
}
