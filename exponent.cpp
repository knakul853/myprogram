#include<bits/stdc++.h>
using namespace std;
long long pow(long long a,long b)
{
    if(b==1) return a;
    long long res=pow(a,b/2);
    if(b%2)res*res*a;
    else
        return res*res;

}
int main(){
long long a,b;
cin>>a>>b;
long long res =pow(a,b);

cout<<res;
}
