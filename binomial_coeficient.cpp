#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll combi(int n,int r)
{
    ll res=1;
    if(r>n-r)
        r=n-r;

    for(int i=0;i<r;i++)
    {
        res*= (n-i);
        res/=(i+1);


    }
    return res;


}
int main()
{
    int n,r;
    cin>>n>>r;
    int res = combi(n,r);
    cout<<res<<endl;
}
