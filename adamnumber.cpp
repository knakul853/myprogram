#include<bits/stdc++.h>
using namespace std;
int revere(int t){
    int b=0;
while(t){
    int r=t%10;
    b=b*10+r;
    t=t/10;
}
return b;
}
int main(){
int a,t;
scanf("%d",&a);
t=a;
int b=revere(t);
t = a*a;
int ar=revere(t);
t= b*b;
int br = revere(t);
int res = revere(br);
if(ar==res)
    cout<<"Adam number\n";
else
    cout<<"Not Adam number\n";


}
