#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a,int b,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
   int res = gcd(b%a,a,&x1,&y1);
   *x =y1-(b/a)*x1;
   *y =x1;
   return res;
}
int main(){

    int n,a,b;
  while(1)
  {
      cin>>a>>b;
      int x,y;
      int res = gcd(a,b,&x,&y);

     cout<<(x<y?x:y)<<" "<<(y>x?y:x)<<" "<<res<<endl;


  }

}
