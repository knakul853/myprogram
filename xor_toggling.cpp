#include<bits/stdc++.h>
using namespace std;
int main(){
int n=6;       //stripping off the lowest bit
int res=n&n-1; // if a number is in 2 th power(n&n-1) it will return zero:
//printf("%d ",res);
int ress=n&(-n);//getting lowest bit
printf("%d ",ress);
}
