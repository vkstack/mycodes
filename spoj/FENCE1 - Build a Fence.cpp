#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int t;
    double pi = 4*atan(1.0);
    int L;
    while(scanf("%d",&L) && L){
        printf("%.2lf\n",(double)(L*L)/(2*pi));
    }
    return 0;
}
